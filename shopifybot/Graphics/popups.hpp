//
// Created by Evan Kirkiles on 7/23/18.
//

#ifndef SHOPIFY_BOT_POPUPS_HPP
#define SHOPIFY_BOT_POPUPS_HPP

#ifndef QWidget
#include <QWidget>
#endif
#ifndef QVBoxLayout
#include <QVBoxLayout>
#endif
#ifndef QHBoxLayout
#include <QHBoxLayout>
#endif
#ifndef QLabel
#include <QLabel>
#endif
#ifndef QPushButton
#include <QPushButton>
#endif
#ifndef QTextStream
#include <QTextStream>
#endif
#ifndef QFile
#include <QFile>
#endif
#ifndef QTextBrowser
#include <QTextBrowser>
#endif
#ifndef QFileInfo
#include <QFileInfo>
#endif
#ifndef QComboBox
#include <QComboBox>
#endif
#ifndef QLineEdit
#include <QLineEdit>
#endif
#ifndef QDateTimeEdit
#include <QDateTimeEdit>
#endif
#ifndef QIntValidator
#include <QIntValidator>
#endif

#include "titlebar.hpp"

// Header containing all the declarations of the different popups available from the mainwindow. These include:
//  1. The log file display used for each individual task
//  2. The task information editor
//  3. The billing info editor
//  4. The proxy list editor
//  5. The information/about popup

// Class for a popup which displays a text file and refreshes it at a specified frequency.
class LogFileDisplay : public QWidget {
    Q_OBJECT
public:
    // Constructor that is given the file path for the file it is to open
    explicit LogFileDisplay(const std::string& title, const std::string& LFlocation, QWidget *parent = 0);

    // Override window closed event
    void closeEvent(QCloseEvent *event) override;

signals:
    // Signal emitted when the window is closed in the overridden closeevent
    void closed();
public slots:
    // Refresher slot that will be connected to a "FILE REFRESH" button, or can also be hooked up to a QTimer
    void refresh();
private:
    // File location is saved in a member string to allow for continuous refreshal
    const std::string title;

    // Widgets on the window
    QLabel* titledisplay;
    QPushButton* refreshButton;
    QFile* logFile;
    QTextStream* logStream;
    QTextBrowser* logDisplay;
protected:
    // Override the lose focus event so it closes whenever the window is left
    void focusOutEvent(QFocusEvent *event) override { close(); }
};

// Window that pops up when you try to add a task
class AddTaskDisplay : public QWidget {
    Q_OBJECT
public:
    // Constructor that builds the window
    explicit AddTaskDisplay(QWidget *parent = 0);

    // Override window closed event
    void closeEvent(QCloseEvent *event) override;

signals:
    // Called whenever the addtask window is closed
    void closed();
    // Sends the information of the new task to the main window to add it
    // TODO: Add the information packets sent
    void sendTask();

private:

    // Dark title bar widget
    DarkTitleBar* dtb;

    // The widgets through which the new task will be added to the client
    // Website and collection row
    QLabel* websitesLabel;
    QComboBox* websites;
    QLabel* collectionLabel;
    QLineEdit* collection;

    // Keyword row
    QLabel* keywordsLabel;
    QLineEdit* keywords;

    // Color Keyword row
    QLabel* colorKeywordsLabel;
    QLineEdit* colorKeywords;

    // Size and time row
    QLabel* sizeLabel;
    QLineEdit* size;
    QLabel* etaLabel;
    QDateTimeEdit* eta;
    QLabel* copiesLabel;
    QLineEdit* copies;

    // Profile and proxy row
    QLabel* profileLabel;
    QComboBox* profile;
    QLabel* proxyLabel;
    QComboBox* proxy;

    // Title row is last with the finished button
    QLabel* titleLabel;
    QLineEdit* title;
    QPushButton* submit;
};

#endif //SHOPIFY_BOT_POPUPS_HPP
