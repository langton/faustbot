//
// Created by Evan Kirkiles on 7/23/18.
//

#include "popups.hpp"

// LOG FILE DISPLAY CLASS
// Constructor that builds the window
LogFileDisplay::LogFileDisplay(const std::string& p_title, const std::string& LFlocation, QWidget *parent) :
        title(p_title), QWidget(parent) {

    // Fixed size of the window
    setFixedSize(500, 300);
    setWindowTitle("Logs");
    setObjectName("logs_window");
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_QuitOnClose, false);

    // Set the stylesheet for the window
    QFile File("./shopifybot/Graphics/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    // Create the window layouts
    auto mainLayout = new QVBoxLayout();
    auto topLayout = new QHBoxLayout();

    // Add the title and the refresh button to the top of the window
    titledisplay = new QLabel(title.c_str(), this);
    titledisplay->setObjectName("task_important_text");
    refreshButton = new QPushButton("REFRESH", this);
    refreshButton->setObjectName("sidebuttons");

    // Add the top layer widgets to the horizontal layout
    topLayout->addWidget(titledisplay);
    topLayout->addWidget(refreshButton);

    // Initialize the logFile and the textstream
    logFile = new QFile(LFlocation.c_str());
    logFile->open(QIODevice::ReadOnly);
    if (logFile->exists()) {
        logStream = new QTextStream(logFile);
        logDisplay = new QTextBrowser();
        logDisplay->setText(logStream->readAll());
    } else {
        logDisplay = new QTextBrowser();
        logDisplay->setText(QString("Log file not yet generated."));
    }

    logDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    logDisplay->setObjectName("logs_text");

    // Add these things to the main layout
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(logDisplay);

    // Set the window's layout
    setLayout(mainLayout);

    // Connect the refresh button to its slot
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(refresh()));
}

// Refresh slot which reloads the filestream into the textbrowser
void LogFileDisplay::refresh() {
    logFile->close();
    logFile->open(QIODevice::ReadOnly);
    if (logFile->exists()) {
        logStream = new QTextStream(logFile);
        logDisplay->setText(logStream->readAll());
    } else {
        logDisplay->setText(QString("Log file not yet generated."));
    }
}

// Custom close event function that just emits a signal signifying it has closed
void LogFileDisplay::closeEvent(QCloseEvent *event) {
    // Emit the closed signal and then proceed to cleanup
    emit closed();
    QWidget::closeEvent(event);
}

// ADD TASK DISPLAY CLASS
// Constructor that builds the window for adding a task
AddTaskDisplay::AddTaskDisplay(QWidget *parent) : QWidget(parent) {

    // Set window properties
    setFixedSize(500, 300);
    setObjectName("newtaskwindow");
    setWindowTitle("New Task");
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);

    // Set the stylesheet for the window
    QFile File("./shopifybot/Graphics/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    // Create layouts
    auto mainLayout = new QVBoxLayout();
    // Individual horizontal row layouts
    auto websiteCollectionLayout = new QHBoxLayout();
    auto keywordLayout = new QHBoxLayout();
    auto colorKeywordLayout = new QHBoxLayout();
    auto sizeEtaLayout = new QHBoxLayout();
    auto frequencyLayout = new QHBoxLayout();
    auto titleLayout = new QHBoxLayout();

    // Create the widgets
    // WEBSITE & COLLECTION ROW
    websitesLabel = new QLabel("Website: ", this);
    websitesLabel->setObjectName("addtask_mediocre_text");
    websites = new QComboBox(this);
    // Change this when adding new websites
    QStringList supportedsites({"Blends", "Bodega", "Kith", "Social Status",  "Undefeated", "WishATL", "XHibition",});
    websites->addItems(supportedsites);
    collectionLabel = new QLabel("Collection: ", this);
    collectionLabel->setObjectName("addtask_mediocre_text");
    collection = new QLineEdit(this);
    collection->setObjectName("addtask_editbox");
    // Add row to the layout
    websiteCollectionLayout->addWidget(websitesLabel);
    websiteCollectionLayout->addWidget(websites);
    websiteCollectionLayout->addWidget(collectionLabel);
    websiteCollectionLayout->addWidget(collection);
    mainLayout->addLayout(websiteCollectionLayout);

    // KEYWORD ROW
    keywordsLabel = new QLabel("Title Keywords: ", this);
    keywordsLabel->setObjectName("addtask_mediocre_text");
    keywords = new QLineEdit(this);
    keywords->setObjectName("addtask_editbox");
    // Add row to the layout
    keywordLayout->addWidget(keywordsLabel);
    keywordLayout->addWidget(keywords);
    mainLayout->addLayout(keywordLayout);

    // COLOR KEYWORD ROW
    colorKeywordsLabel = new QLabel("Color Keywords: ", this);
    colorKeywordsLabel->setObjectName("addtask_mediocre_text");
    colorKeywords = new QLineEdit(this);
    colorKeywords->setObjectName("addtask_editbox");
    // Add row to the layout
    colorKeywordLayout->addWidget(colorKeywordsLabel);
    colorKeywordLayout->addWidget(colorKeywords);
    mainLayout->addLayout(colorKeywordLayout);

    // SIZE & PROXY ROW
    sizeLabel = new QLabel("Size: ", this);
    sizeLabel->setObjectName("addtask_mediocre_text");
    sizeLabel->setMaximumWidth(35);
    size = new QLineEdit(this);
    size->setObjectName("addtask_editbox");
    size->setMaximumWidth(35);
    etaLabel = new QLabel("Start at: ", this);
    etaLabel->setObjectName("addtask_mediocre_text");
    etaLabel->setMaximumWidth(60);
    eta = new QDateTimeEdit(this);
    eta->setObjectName("addtask_datetime");
    eta->setDisplayFormat("[MMMM d, yyyy] h:mm AP");
    eta->setDateTime(QDateTime::currentDateTime());
    copiesLabel = new QLabel("Copies: ", this);
    copiesLabel->setObjectName("addtask_mediocre_text");
    copiesLabel->setMaximumWidth(45);
    copies = new QLineEdit(this);
    copies->setObjectName("addtask_editbox");
    copies->setValidator(new QIntValidator(0, 20, this));
    copies->setText("1");
    copies->setMaximumWidth(35);
    // Add row to the layout
    sizeEtaLayout->addStretch();
    sizeEtaLayout->addWidget(sizeLabel);
    sizeEtaLayout->addWidget(size);
    sizeEtaLayout->addWidget(etaLabel);
    sizeEtaLayout->addWidget(eta);
    sizeEtaLayout->addWidget(copiesLabel);
    sizeEtaLayout->addWidget(copies);
    sizeEtaLayout->addStretch();
    mainLayout->addLayout(sizeEtaLayout);

    // FREQUENCY & PROXY ROW
    profileLabel = new QLabel("Profile: ", this);
    profileLabel->setObjectName("addtask_mediocre_text");
    profileLabel->setMaximumWidth(50);
    profile = new QComboBox(this);
    proxyLabel = new QLabel("Proxy: ", this);
    proxyLabel->setObjectName("addtask_mediocre_text");
    proxyLabel->setMaximumWidth(45);
    proxy = new QComboBox(this);
    // Add row to the layout
    frequencyLayout->addWidget(profileLabel);
    frequencyLayout->addWidget(profile);
    frequencyLayout->addWidget(proxyLabel);
    frequencyLayout->addWidget(proxy);
    mainLayout->addLayout(frequencyLayout);

    // TITLE ROW
    titleLabel = new QLabel("Title: ", this);
    titleLabel->setObjectName("task_important_text");
    title = new QLineEdit(this);
    title->setObjectName("task_title_lineedit");
    submit = new QPushButton("SUBMIT", this);
    submit->setObjectName("addtaskbutton");
    submit->setFixedSize(100, 35);
    // Add row to the layout
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(title);
    titleLayout->addSpacing(10);
    titleLayout->addWidget(submit);
    mainLayout->addLayout(titleLayout);

    // Set the layout
    setLayout(mainLayout);
}

// Custom close event function that just emits a signal signifying it has closed
void AddTaskDisplay::closeEvent(QCloseEvent *event) {
    // Emit the closed signal and then proceed to cleanup
    emit closed();
    QWidget::closeEvent(event);
}