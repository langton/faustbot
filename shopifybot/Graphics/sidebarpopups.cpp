//
// Created by Evan Kirkiles on 8/1/18.
//

#include <shopifybot/WebAccess/product_scraper.hpp>
#include "sidebarpopups.hpp"

// PROFILES DISPLAY
// Constructor that builds the profiles display
ProfilesDisplay::ProfilesDisplay(QWidget *parent) : addProfileButton(new ClickableImage(26, 26, 2, file_paths::ADD2_IMG,
                                                                                        file_paths::ADD_IMG, this)),
                                                    duplicateProfileButton(new ClickableImage(26, 26, 2, file_paths::DUPLICATE2_IMG,
                                                                                        file_paths::DUPLICATE_IMG, this)),
                                                    deleteProfileButton(new ClickableImage(26, 26, 2, file_paths::MINUS2_IMG,
                                                                                        file_paths::MINUS_IMG, this)),
                                                    addCreditCardButton(new ClickableImage(26, 26, 2, file_paths::ADD2_IMG,
                                                                                        file_paths::ADD_IMG, this)),
                                                    deleteCreditCardButton(new ClickableImage(26, 26, 2, file_paths::MINUS2_IMG,
                                                                                        file_paths::MINUS_IMG, this)),
                                                    editCreditCardButton(new ClickableImage(26, 26, 2, file_paths::EDIT2_IMG,
                                                                                        file_paths::EDIT_IMG, this)),
                                                    profilesListView(new QListWidget(this)),
                                                    profileViewTitle(new QLabel("Profiles", this)),
                                                    titleLabel(new QLabel("Title: ", this)),
                                                    editTitle(new QLineEdit(this)),
                                                    emailLabel(new QLabel("Email:", this)),
                                                    email(new QLineEdit(this)),
                                                    firstnameLabel(new QLabel("First name:", this)),
                                                    firstname(new QLineEdit(this)),
                                                    lastnameLabel(new QLabel("Last name:", this)),
                                                    lastname(new QLineEdit(this)),
                                                    address1Label(new QLabel("Address:", this)),
                                                    address1(new QLineEdit(this)),
                                                    address2Label(new QLabel("Apartment, Suite, etc:", this)),
                                                    address2(new QLineEdit(this)),
                                                    cityLabel(new QLabel("City:", this)),
                                                    city(new QLineEdit(this)),
                                                    zipcodeLabel(new QLabel("Zip Code:", this)),
                                                    zipcode(new QLineEdit(this)),
                                                    provinceLabel(new QLabel("Province:", this)),
                                                    province(new QLineEdit(this)),
                                                    countryLabel(new QLabel("Country:", this)),
                                                    country(new QLineEdit(this)),
                                                    phoneLabel(new QLabel("Phone:", this)),
                                                    phone(new QLineEdit(this)),
                                                    ccardLabel(new QLabel("Credit Card:", this)),
                                                    ccard(new QComboBox(this)),
                                                    update(new QPushButton("UPDATE", this)),
                                                    creditcardViewTitle(new QLabel("Credit Cards", this)),
                                                    creditcardsListView(new QListWidget(this)),
                                                    QWidget(parent) {

    // Set window properties
    setFixedSize(500, 500);
    setWindowTitle("Profiles");
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this, true);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Create normal layouts
    auto mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(11, 3, 11, 11);
    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    auto leftColumnWidg = new QWidget();
    auto leftColumn = new QVBoxLayout();
    leftColumnWidg->setLayout(leftColumn);
    leftColumnWidg->setSizePolicy(spLeft);
    leftColumn->setContentsMargins(0, 0, 0, 0);
    auto smallButtonRow = new QHBoxLayout();
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(2);
    profileViewTitle->setObjectName("addtask_mediocre_text");
    smallButtonRow->addWidget(profileViewTitle);
    smallButtonRow->addWidget(addProfileButton);
    smallButtonRow->addWidget(duplicateProfileButton);
    smallButtonRow->addWidget(deleteProfileButton);
    auto secondSmallButtonRow = new QHBoxLayout();
    creditcardViewTitle->setObjectName("addtask_mediocre_text");
    secondSmallButtonRow->addWidget(creditcardViewTitle);
    secondSmallButtonRow->addWidget(addCreditCardButton);
    secondSmallButtonRow->addWidget(deleteCreditCardButton);
    secondSmallButtonRow->addWidget(editCreditCardButton);
    auto rightColumnWidg = new QWidget();
    auto rightColumn = new QVBoxLayout();
    rightColumnWidg->setLayout(rightColumn);
    rightColumnWidg->setSizePolicy(spRight);
    rightColumn->setContentsMargins(0, 0, 0, 0);
    auto emailRow = new QHBoxLayout();
    auto titleRow = new QHBoxLayout();
    auto fNameRow = new QHBoxLayout();
    auto lNameRow = new QHBoxLayout();
    auto address1Row = new QHBoxLayout();
    auto address2Row = new QHBoxLayout();
    auto cityZipRow = new QHBoxLayout();
    auto countryRow = new QHBoxLayout();
    auto phoneRow = new QHBoxLayout();
    auto ccardRow = new QHBoxLayout();

    // Create the widgets and add them to their respective layouts
    leftColumn->addLayout(smallButtonRow);
    profilesListView->setObjectName("profileslistview");
    profilesListView->setSelectionMode(QAbstractItemView::SingleSelection);
    profilesListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    profilesListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    leftColumn->addWidget(profilesListView);
    leftColumn->addLayout(secondSmallButtonRow);
    creditcardsListView->setObjectName("profileslistview");
    creditcardsListView->setMaximumHeight(120);
    creditcardsListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    creditcardsListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    profilesListView->setSelectionMode(QAbstractItemView::SingleSelection);
    leftColumn->addWidget(creditcardsListView);
    titleLabel->setObjectName("task_important_text");
    editTitle->setObjectName("task_title_lineedit");
    connect(editTitle, &QLineEdit::textEdited, [this] () {
        editTitle->setObjectName("task_title_lineedit");
        editTitle->setStyleSheet(editTitle->styleSheet());
    } );
    titleRow->addWidget(titleLabel);
    titleRow->addWidget(editTitle);
    emailLabel->setObjectName("addtask_mediocre_text");
    email->setObjectName("addtask_editbox");
    connect(email, &QLineEdit::textEdited, [this] () {
        email->setObjectName("addtask_editbox");
        email->setStyleSheet(email->styleSheet());
    } );
    emailRow->addWidget(emailLabel);
    emailRow->addWidget(email);
    firstnameLabel->setObjectName("addtask_mediocre_text");
    firstname->setObjectName("addtask_editbox");
    connect(firstname, &QLineEdit::textEdited, [this] () {
        firstname->setObjectName("addtask_editbox");
        firstname->setStyleSheet(firstname->styleSheet());
    } );
    fNameRow->addWidget(firstnameLabel);
    fNameRow->addWidget(firstname);
    lastnameLabel->setObjectName("addtask_mediocre_text");
    lastname->setObjectName("addtask_editbox");
    connect(lastname, &QLineEdit::textEdited, [this] () {
        lastname->setObjectName("addtask_editbox");
        lastname->setStyleSheet(lastname->styleSheet());
    } );
    lNameRow->addWidget(lastnameLabel);
    lNameRow->addWidget(lastname);
    address1Label->setObjectName("addtask_mediocre_text");
    address1->setObjectName("addtask_editbox");
    connect(address1, &QLineEdit::textEdited, [this] () {
        address1->setObjectName("addtask_editbox");
        address1->setStyleSheet(address1->styleSheet());
    } );
    address1Row->addWidget(address1Label);
    address1Row->addWidget(address1);
    address2Label->setObjectName("addtask_mediocre_text");
    address2->setObjectName("addtask_editbox");
    connect(address2, &QLineEdit::textEdited, [this] () {
        address2->setObjectName("addtask_editbox");
        address1->setStyleSheet(address2->styleSheet());
    } );
    address2Row->addWidget(address2Label);
    address2Row->addWidget(address2);
    cityLabel->setObjectName("addtask_mediocre_text");
    city->setObjectName("addtask_editbox");
    connect(city, &QLineEdit::textEdited, [this] () {
        city->setObjectName("addtask_editbox");
        city->setStyleSheet(city->styleSheet());
    } );
    cityZipRow->addWidget(cityLabel);
    cityZipRow->addWidget(city);
    zipcodeLabel->setObjectName("addtask_mediocre_text");
    zipcode->setObjectName("addtask_editbox");
    zipcode->setMaximumWidth(60);
    connect(zipcode, &QLineEdit::textEdited, [this] () {
        zipcode->setObjectName("addtask_editbox");
        zipcode->setStyleSheet(zipcode->styleSheet());
    } );
    cityZipRow->addWidget(zipcodeLabel);
    cityZipRow->addWidget(zipcode);
    countryLabel->setObjectName("addtask_mediocre_text");
    country->setObjectName("addtask_editbox");
    connect(country, &QLineEdit::textEdited, [this] () {
        country->setObjectName("addtask_editbox");
        country->setStyleSheet(country->styleSheet());
    } );
    provinceLabel->setObjectName("addtask_mediocre_text");
    province->setObjectName("addtask_editbox");
    connect(province, &QLineEdit::textEdited, [this] () {
        province->setObjectName("addtask_editbox");
        province->setStyleSheet(province->styleSheet());
    } );
    countryRow->addWidget(countryLabel);
    countryRow->addWidget(country);
    countryRow->addWidget(provinceLabel);
    countryRow->addWidget(province);
    phoneLabel->setObjectName("addtask_mediocre_text");
    phone->setObjectName("addtask_editbox");
    connect(phone, &QLineEdit::textEdited, [this] () {
        phone->setObjectName("addtask_editbox");
        phone->setStyleSheet(phone->styleSheet());
    } );
    phoneRow->addWidget(phoneLabel);
    phoneRow->addWidget(phone);
    ccardLabel->setObjectName("addtask_mediocre_text");
    connect(ccard, &QComboBox::currentTextChanged, [this] () {
        ccard->setObjectName("");
        ccard->setStyleSheet(ccard->styleSheet());
    } );
    update->setObjectName("addtaskbutton");
    update->setFixedSize(100, 35);
    ccardRow->addWidget(ccardLabel);
    ccardRow->addWidget(ccard);
    ccardRow->addWidget(update);

    // Finish adding all the layouts
    mainLayout->addWidget(leftColumnWidg);
    mainLayout->addWidget(rightColumnWidg);
    rightColumn->addLayout(titleRow);
    rightColumn->addLayout(emailRow);
    rightColumn->addLayout(fNameRow);
    rightColumn->addLayout(lNameRow);
    rightColumn->addLayout(address1Row);
    rightColumn->addLayout(address2Row);
    rightColumn->addLayout(cityZipRow);
    rightColumn->addLayout(countryRow);
    rightColumn->addLayout(phoneRow);
    rightColumn->addLayout(ccardRow);
    bgLayout->addLayout(mainLayout);

    // Set the layout finally
    setLayout(externLayout);

    // Connect the update button to the submit
    connect(update, SIGNAL(clicked()), this, SLOT(submit()));
    // Connect the select function to the signal produced by the qlistwidget
    connect(profilesListView, SIGNAL(currentTextChanged(QString)), this, SLOT(select(QString)));
    // Connect the add new function to the signal produced by clicking the plus button
    connect(addProfileButton, SIGNAL(clicked()), this, SLOT(createNew()));
    // Connect the duplicate function to the signal produced by clicking the dupe button
    connect(duplicateProfileButton, SIGNAL(clicked()), this, SLOT(duplicateProfile()));
    // Connect the delete function to the signal produced by clicking the subtract button
    connect(deleteProfileButton, SIGNAL(clicked()), this, SLOT(deleteProfile()));
    // Connect the add credit card function to hte signal produced by clicking the lower add button
    connect(addCreditCardButton, SIGNAL(clicked()), this, SLOT(addCC()));
    // Connect the edit credit card function to the signal produced by clicking the edit button
    connect(editCreditCardButton, &ClickableImage::clicked, [this] () {
        // Make sure that there is actually a selected credit card profile
        if (!creditcardsListView->selectedItems().isEmpty()) {
            editCC();
        }});
    // Connect the delete credit card function to the signal produced by clicking the delete button
    connect(deleteCreditCardButton, SIGNAL(clicked()), this, SLOT(deleteCC()));

    // Fill in the profiles listview
    refresh();
    // Fill in the credit card listview
    refreshCC();

    // Make sure credit card begins correct color
    ccard->setObjectName("combobox_unchanged");
}
// Override the column for the profiles display
void ProfilesDisplay::closeEvent(QCloseEvent* event) {
    emit closed();
    QWidget::closeEvent(event);
}
// Refreshes the list of profiles, should be called after updates
void ProfilesDisplay::refresh(int selected) {
    // Rereads the profiles file and builds the qlist of profile titles for the listview
    std::ifstream fin(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());
    std::string str;

    // Reset the list view
    profilesListView->clear();

    // Cycle through the lines and get the title of each profile (comes before the ":-:")
    while (getline(fin, str)) {
        // Check for the title identifier and add the preceding substring to the qlist
        const unsigned long titlePos = str.find(" :-:");
        if (titlePos != std::string::npos) {
            profilesListView->addItem(str.substr(0, titlePos).c_str());
        }
    }

    // Close the file
    fin.close();

    // Select a specified item, useful for the submit function
    profilesListView->setCurrentRow(selected);
}
// Refreshes the list of credit cards, should be called after updates
void ProfilesDisplay::refreshCC(int selected) {
    // Rereads the credit cards file and builds the qlist of credit card titles for the listview
    std::ifstream fin(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
    std::string str;

    // Reset the list view
    creditcardsListView->clear();

    // Cycle through the lines and get the title of each credit card profile
    while (getline(fin, str)) {
        // Check for the title identifier and add the preceding substring to the QList
        const unsigned long titlePos = str.find(" :-:");
        if (titlePos != std::string::npos) {
            creditcardsListView->addItem(str.substr(0, titlePos).c_str());
        }
    }

    // Close the file
    fin.close();

    // Select the specified item, useful for the submit function
    creditcardsListView->setCurrentRow(selected);

    // Reset the QComboBox containing all the credit cards for the edit task function
    resetCreditCardQCB();
}
// Changes the text fields to the selected profile's information
void ProfilesDisplay::select(QString which) {
    // Reads the profiles file and finds the JSON data for the given profile title
    std::ifstream fin(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());
    std::string str;

    // Cycle through the lines and get the title of each profile
    while (getline(fin, str)) {
        // Check for the title identifier and parse through its JSON data
        const unsigned long titlePos = str.find(std::string(" :-:"));
        if (str.substr(0, titlePos) == which.toStdString()) {
            str = str.substr(titlePos + 4);
            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(str.c_str()).toUtf8());
            QJsonObject jsonObject = jsonDoc.object();

            // Use the JSON object to fill in the data fields
            editTitle->setText(which);
            editTitle->setObjectName("task_title_lineedit_unchanged");
            editTitle->setStyleSheet(editTitle->styleSheet());
            email->setText(jsonObject.value("email").toString());
            email->setObjectName("addtask_editbox_unchanged");
            email->setStyleSheet(email->styleSheet());
            firstname->setText(jsonObject.value("firstname").toString());
            firstname->setObjectName("addtask_editbox_unchanged");
            firstname->setStyleSheet(firstname->styleSheet());
            lastname->setText(jsonObject.value("lastname").toString());
            lastname->setObjectName("addtask_editbox_unchanged");
            lastname->setStyleSheet(lastname->styleSheet());
            address1->setText(jsonObject.value("address1").toString());
            address1->setObjectName("addtask_editbox_unchanged");
            address1->setStyleSheet(address1->styleSheet());
            address2->setText(jsonObject.value("address2").toString());
            address2->setObjectName("addtask_editbox_unchanged");
            address2->setStyleSheet(address2->styleSheet());
            city->setText(jsonObject.value("city").toString());
            city->setObjectName("addtask_editbox_unchanged");
            city->setStyleSheet(city->styleSheet());
            country->setText(jsonObject.value("country").toString());
            country->setObjectName("addtask_editbox_unchanged");
            country->setStyleSheet(country->styleSheet());
            province->setText(jsonObject.value("province").toString());
            province->setObjectName("addtask_editbox_unchanged");
            province->setStyleSheet(province->styleSheet());
            zipcode->setText(jsonObject.value("zipcode").toString());
            zipcode->setObjectName("addtask_editbox_unchanged");
            zipcode->setStyleSheet(zipcode->styleSheet());
            phone->setText(jsonObject.value("phone").toString());
            phone->setObjectName("addtask_editbox_unchanged");
            phone->setStyleSheet(phone->styleSheet());
            ccard->setCurrentText(jsonObject.value("ccard").toString());
            ccard->setObjectName("combobox_unchanged");
            ccard->setStyleSheet(ccard->styleSheet());

            break;
        }
    }
}
// Submits the text to the profiles.txt
void ProfilesDisplay::submit() {
    // Make sure there is actually a selected item
    if (profilesListView->selectedItems().isEmpty()) {
        return;
    }

    // Initialize input/output streams
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str());
    if (!filein || !fileout) { throw std::runtime_error("Error opening profiles file."); }

    // Cycle through the input file until the correct line is found
    std::string strTemp;
    bool titleNotChanged = true;
    while (getline(filein, strTemp)) {
        // When it finds the correct title, change the text to the JSON formatted string
        if (strTemp.substr(0, strTemp.find(" :-:")) == profilesListView->currentItem()->text().toStdString() && titleNotChanged) {

            // If there already exists a profile by the same name, edit the title

            strTemp = getSafeName(false, profilesListView->currentRow(), editTitle->text().toStdString()) +
                    R"( :-: {"email":")" + email->text().toStdString() +
                    R"(","firstname":")" + firstname->text().toStdString() + R"(","lastname":")" +
                      lastname->text().toStdString() + R"(","address1":")" + address1->text().toStdString() +
                    R"(","address2":")" + address2->text().toStdString() + R"(","city":")" +
                      city->text().toStdString() + R"(","country":")" + country->text().toStdString() +
                      R"(","province":")" + province->text().toStdString() + R"(","zipcode":")" +
                      zipcode->text().toStdString() + R"(","phone":")" + phone->text().toStdString() +
                      R"(","ccard":")" + ccard->currentText().toStdString() + R"("})";
            titleNotChanged = false;
        }

        // Finalize the string formatting and write it to the output file
        fileout << strTemp << "\n";
    }

    // Close the files used
    filein.close();
    fileout.close();

    // Rename the output file to the input file so it overwrites it and is picked up by the listview
    std::rename(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str(),
                QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());

    // Finally update the qlistview display
    refresh(profilesListView->currentRow());
}

// Slot that creates a new profile (called when the plus button is clicked)
void ProfilesDisplay::createNew() {

    // Opens the profiles file and adds a new profile to the end
    std::ofstream profilesFile(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str(),
                               std::ios_base::app | std::ios_base::out);
    profilesFile << getSafeName(true) + R"( :-: {"email":","firstname":"","lastname":"","address1":"","address2":"","city":"","country":"","province":"","zipcode":"","phone":"","ccard":"Random"})" + "\n";
    profilesFile.close();

    // Then refreshes the profiles view and selects the most recent addition
    refresh(profilesListView->count());
}

// Gets a safe, unique name for a profile, default is Untitled (for add new case)
std::string ProfilesDisplay::getSafeName(bool addingnew, const int currentIndex, std::string title) {

    // Remove whitespace from the end of the title
    rtrim(title);

    // If the profilesListView is empty, then simply return the title without ending whitespace
    if (profilesListView->count() == 0) { return title; }

    // Iterate through the names and search for number add-on availiability
    bool nameFound = false;
    unsigned int modNum = 0;
    std::string modifier;
    while (!nameFound) {

        // Iterate through the current profile names
        for (int i = 0; i < profilesListView->count(); i++) {
            nameFound = false;
            QListWidgetItem* item = profilesListView->item(i);
            // Skip the current index of the profile being edited
            if (i == currentIndex && !addingnew) { nameFound = true; continue; }

            // If a match is found, update the modifier and rerun the loop
            if (item->text().toStdString() == title + modifier) {
                modNum++;
                modifier = " (" + std::to_string(modNum) + ")";
                break;
            }
            nameFound = true;
        }
    }

    return title + modifier;
}

// Duplicates the currently selected profile
void ProfilesDisplay::duplicateProfile() {
    // Initialize input/output streams
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str());
    if (!filein || !fileout) { throw std::runtime_error("Error opening profiles file."); }

    // Find the line with the selected profile, then duplicate it in the temp file
    std::string strTemp;
    std::string toDuplicate;
    while (getline(filein, strTemp)) {
        // Check if the line matches the designated duplicate file
        std::string title = profilesListView->currentItem()->text().toStdString();
        if (strTemp.substr(0, strTemp.find(" :-:")) == title) {
            // If it does, then write the line and then write a second same line in the temp file
            fileout << strTemp << "\n" << getSafeName(true, 0, title) << strTemp.substr(title.length()) << "\n";
        } else {
            fileout << strTemp << "\n";
        }
    }

    // Close the files used
    filein.close();
    fileout.close();

    // Rename the output file to the input file so it overwrites it and is picked up by the listview
    std::rename(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str(),
                QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());

    // Finally update the qlistview display
    refresh(profilesListView->currentRow() + 1);
}

// Deletes the currently selected profile
void ProfilesDisplay::deleteProfile() {
    // Initialize input/output streams
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str());
    if (!filein || !fileout) { throw std::runtime_error("Error opening profiles file."); }

    // Find the line with the given profile; then delete it in the temp file
    std::string strTemp;
    while(getline(filein, strTemp)) {
        // When it finds the correct title, do not write the line
        if (strTemp.substr(0, strTemp.find(" :-:")) != profilesListView->currentItem()->text().toStdString()) {
            fileout << strTemp << "\n";
        }
    }

    // Close the files used
    filein.close();
    fileout.close();

    // Rename the output file to the input file so it overwrites it and is picked up by the listview
    std::rename(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str(),
                QApplication::applicationDirPath().append(file_paths::PROFILES_TXT).toStdString().c_str());

    // Finally update the qlistview display
    refresh(std::max(profilesListView->currentRow() - 1, 0));

    // If the last one has been deleted, then clear all the input fields
    if (profilesListView->count() == 0) {
        editTitle->setText("");
        email->setText("");
        firstname->setText("");
        lastname->setText("");
        address1->setText("");
        address2->setText("");
        city->setText("");
        country->setText("");
        province->setText("");
        zipcode->setText("");
        phone->setText("");
        ccard->setCurrentText("Random");
    }
}

// Builds the add credit card display
void ProfilesDisplay::addCC() {

    // If there is already a window open, then just raise it
    if (accdOpen) {
        accd->raise();
        accd->setFocus();
        return;
    }
    // Otherwise build a new add credit card window and show it
    accd = new AddCreditCardDisplay();
    accd->show();
    accdOpen = true;

    // Make necessary connections
    connect(accd, &AddCreditCardDisplay::closed, [this] () { accdOpen = false; });
    connect(accd, &AddCreditCardDisplay::submitted, [this] () {
        if (accd->windowTitle().toStdString().substr(0, 3) == "Add") {
            refreshCC(creditcardsListView->count() + 1);
        } else {
            refreshCC(creditcardsListView->currentRow());
        }
    });
}

// Opens the edit credit card display
void ProfilesDisplay::editCC() {

    // If there is already a window open, then just raise it
    if (accdOpen) {
        accd->raise();
        accd->setFocus();
        return;
    }
    // Otherwise build a new edit credit card window and show it
    accd = new AddCreditCardDisplay(creditcardsListView->currentItem()->text());
    accd->show();
    accdOpen = true;

    // Make necessary connections
    connect(accd, &AddCreditCardDisplay::closed, [this] () { accdOpen = false; });
    connect(accd, &AddCreditCardDisplay::submitted, [this] () {
        if (accd->windowTitle().toStdString().substr(0, 3) == "Add") {
            refreshCC(creditcardsListView->count() + 1);
        } else {
            refreshCC(creditcardsListView->currentRow());
        }
    });
}

// Deletes a credit card profile
void ProfilesDisplay::deleteCC() {

    // If there is an edit window open or new file window, close it
    if (accdOpen) { accd->close(); }

    // Cycle through the ccard text file
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPCCARD_TXT).toStdString().c_str());
    std::string str;
    while(getline(filein, str)) {

        // Write the lines to the temporary credit card text file except for the one with the same title
        if (str.substr(0, str.find(" :-:")) != creditcardsListView->currentItem()->text().toStdString()) {
            fileout << str << "\n";
        }
    }

    // Close the files
    filein.close();
    fileout.close();

    // Rename the temporary credit card list to the real one
    rename(QApplication::applicationDirPath().append(file_paths::TEMPCCARD_TXT).toStdString().c_str(),
           QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());

    // Refresh the credit cards list
    refreshCC(std::max(0, creditcardsListView->currentRow() - 1));
}

// Resets the Credit Card QCB with all the credit cards profiles in the text file
void ProfilesDisplay::resetCreditCardQCB() {

    // Store the QString of the selected item for ease of access
    QString selectedItem = ccard->currentText();

    // First clear the credit card profiles and then add "Random"
    ccard->clear();
    ccard->addItem("Random");

    // Open the filein
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
    std::string str;

    // Cycle through the lines and get the titles of each credit card profile
    while (getline(filein, str)) {
        // Title is found before every " :-:"
        ccard->addItem(str.substr(0, str.find(" :-:")).c_str());
    }

    // Close the file
    filein.close();

    // Set the current text back to the selected item
    ccard->setCurrentText(selectedItem);
}

// ADD CREDIT CARD DISPLAY
// Constructor which builds the credit card add display
AddCreditCardDisplay::AddCreditCardDisplay(const QString profiletitle, QWidget *parent) :
        titleLabel(new QLabel("Title:", this)),
        title(new QLineEdit(this)),
        ccnumLabel(new QLabel("Credit Card:", this)),
        ccnum(new QLineEdit(this)),
        ccnameLabel(new QLabel("Name:", this)),
        ccname(new QLineEdit(this)),
        ccdateLabel(new QLabel("Expiry Date:", this)),
        ccdate(new QDateEdit(this)),
        ccccvLabel(new QLabel("CCV:", this)),
        ccccv(new QLineEdit(this)),
        submit(new QPushButton("ADD", this)),
        ccprofiletitle(profiletitle),
        QWidget(parent) {

    // Set window properties
    setFixedSize(400, 200);
    if (!ccprofiletitle.isEmpty()) {
        setWindowTitle(QString(std::string("Edit Credit Card \"" + ccprofiletitle.toStdString() + "\"").c_str()));
        submit->setText("UPDATE");
    } else {
        setWindowTitle("Add Credit Card");
    }
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this, true);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Create sub layouts
    auto mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(11, 3, 11, 11);
    auto titleLayout = new QHBoxLayout();
    mainLayout->addLayout(titleLayout);
    auto ccnumLayout = new QHBoxLayout();
    mainLayout->addLayout(ccnumLayout);
    auto ccnameLayout = new QHBoxLayout();
    mainLayout->addLayout(ccnameLayout);
    auto ccdateccvsubmitLayout = new QHBoxLayout();
    mainLayout->addLayout(ccdateccvsubmitLayout);

    // Add the labels and lineedits
    titleLabel->setObjectName("task_important_text");
    title->setObjectName("task_title_lineedit");
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(title);
    ccnumLabel->setObjectName("addtask_mediocre_text");
    ccnum->setObjectName("addtask_editbox");
    ccnum->setPlaceholderText("xxxx xxxx xxxx xxxx");
    ccnumLayout->addWidget(ccnumLabel);
    ccnumLayout->addWidget(ccnum);
    ccnameLabel->setObjectName("addtask_mediocre_text");
    ccname->setObjectName("addtask_editbox");
    ccnameLayout->addWidget(ccnameLabel);
    ccnameLayout->addWidget(ccname);
    ccdateLabel->setObjectName("addtask_mediocre_text");
    ccdate->setObjectName("task_dateedit");
    ccdate->setDisplayFormat("MM/yy");
    ccccvLabel->setObjectName("addtask_mediocre_text");
    ccccv->setObjectName("addtask_editbox");
    ccccv->setContentsMargins(0, 0, 5, 0);
    ccccv->setPlaceholderText("xxx");
    submit->setObjectName("addtaskbutton");
    submit->setFixedSize(100, 35);
    ccdateccvsubmitLayout->addWidget(ccdateLabel);
    ccdateccvsubmitLayout->addWidget(ccdate);
    ccdateccvsubmitLayout->addWidget(ccccvLabel);
    ccdateccvsubmitLayout->addWidget(ccccv);
    ccdateccvsubmitLayout->addWidget(submit);

    // If editing, then fill the credit card info
    if (!ccprofiletitle.isEmpty()) {
        fillCCInfo();
    }

    // Set the layouts
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Connect the signals to the slots
    connect(submit, SIGNAL(clicked()), this, SLOT(submitEditOrNew()));
}

// Fills in the necessary fields for when editing a card
void AddCreditCardDisplay::fillCCInfo() {

    // Searches the credit card text file for the given title being edited
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
    std::string strTemp;

    // Cycle through the Credit Card profiles until a match is found
    while (getline(filein, strTemp)) {
        // Check for the title identifier and parse through its JSON data
        const unsigned long titlePos = strTemp.find(std::string(" :-:"));
        if (strTemp.substr(0, titlePos) == ccprofiletitle.toStdString()) {
            strTemp = strTemp.substr(titlePos + 4);
            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(strTemp.c_str()).toUtf8());
            QJsonObject jsonObject = jsonDoc.object();

            // Use the JSON object to fill in the data fields
            title->setText(ccprofiletitle);
            ccnum->setText(jsonObject.value("ccnum").toString());
            ccname->setText(jsonObject.value("ccname").toString());
            QDate expiryDate = QDate::fromString(jsonObject.value("ccmonth").toString() + QString("/") + jsonObject.value("ccyear").toString(), QString("M/yyyy"));
            ccdate->setDate(expiryDate);
            ccccv->setText(jsonObject.value("ccccv").toString());
        }
    }

}

// Submits the new credit card
void AddCreditCardDisplay::submitEditOrNew() {

    // First case is just when it is a new task
    if (windowTitle().toStdString().substr(0, 3) == "Add") {

        // Takes the information from the new credit card form and puts it in the credit card text file
        std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str(), std::ios_base::app | std::ios_base::out);

        // First, make sure that all the required fields are filled
        if (title->text().isEmpty()) { title->setFocus(); return; }
        if (ccnum->text().isEmpty() || ccnum->text().length() != 19) { ccnum->setFocus(); return; }
        if (ccname->text().isEmpty()) { ccname->setFocus(); return; }
        if (ccccv->text().isEmpty() || ccccv->text().length() != 3) { ccccv->setFocus(); return; }

        // Then write a new credit card with the data in the text edits
        fileout << getSafeName(ccprofiletitle.toStdString(), title->text().toStdString()) << R"( :-: {"ccnum":")" <<
                ccnum->text().toStdString() << R"(","ccname":")" << ccname->text().toStdString() << R"(","ccmonth":")" <<
                ccdate->date().month() << R"(","ccyear":")" << ccdate->date().year() << R"(","ccccv":")" <<
                ccccv->text().toStdString() << R"("})" << "\n";

        // Close the file
        fileout.close();

        // Emit the correct signals
        emit submitted();
        close();

        // Second case is when the task is being edited
    } else {
        // Takes the information from the edited credit card and puts it in the credit card text file
        std::ifstream filein(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
        std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPPROFILES_TXT).toStdString().c_str());
        std::string str;

        // First, make sure that all the required fields are filled
        if (title->text().isEmpty()) { title->setFocus(); return; }
        if (ccnum->text().isEmpty() || ccnum->text().length() != 19) { ccnum->setFocus(); return; }
        if (ccname->text().isEmpty()) { ccname->setFocus(); return; }
        if (ccccv->text().isEmpty() || ccccv->text().length() != 3) { ccccv->setFocus(); return; }

        // Cycle through each line until the correct line is found
        while (getline(filein, str)) {
            // Check the title of each cc line against that of the requested edit
            const unsigned long titlePos = str.find(" :-:");
            if (str.substr(0, titlePos) == ccprofiletitle.toStdString()) {
                // Write the edited file to the outfile
                fileout << getSafeName(ccprofiletitle.toStdString(), title->text().toStdString()) << R"( :-: {"ccnum":")" <<
                    ccnum->text().toStdString() << R"(","ccname":")" << ccname->text().toStdString() << R"(","ccmonth":")" <<
                    ccdate->date().month() << R"(","ccyear":")" << ccdate->date().year() << R"(","ccccv":")" <<
                    ccccv->text().toStdString() << R"("})" << "\n";
            } else { fileout << str << "\n"; }
        }

        // Finally, close the files
        filein.close();
        fileout.close();

        // Rename the temporary credit card file to the real one
        rename(QApplication::applicationDirPath().append(file_paths::TEMPCCARD_TXT).toStdString().c_str(),
               QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());

        // Emit the correct signals
        emit submitted();
        close();
    }
}

// Gets a safe name for the credit card profile
std::string AddCreditCardDisplay::getSafeName(std::string currentTitle, std::string title) {

    // Remove whitespace from the end of the title
    rtrim(title);

    // Make sure the title is actually changing
    if (title == currentTitle) { return title; }

    // Cycle through the credit card names in the credit card text file
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::CCARD_TXT).toStdString().c_str());
    // Make sure that the credit cards file actually has contents
    if (filein.peek() == std::ifstream::traits_type::eof()) { return title; }
    std::string str;
    int modifierNum = 0;
    std::string modifier;
    bool foundName = false;

    // Go until a name is found
    while (!foundName) {
        // Check for the title at each line, if found then break and retry
        while(getline(filein, str)) {
            foundName = false;
            // Reformat the string to be just the line's title
            str = str.substr(0, str.find(" :-:"));
            // Now try to make a unique title for the credit card profile
            if (str == title + modifier) {
                modifierNum++;
                modifier = std::string(" (") + std::to_string(modifierNum) + ")";
                break;
            }
            // If it gets through all, then continue and return the title
            foundName = true;
        }
    }

    // When finished, close the file and return the unique name found
    filein.close();

    return title + modifier;
}

// Override the window closed display
void AddCreditCardDisplay::closeEvent(QCloseEvent *event) {
    emit closed();
    QWidget::closeEvent(event);
}

// PROXY DISPLAY CLASS
// Proxy list item which is used by the proxy listview
ProxyListItem::ProxyListItem(QString index, QString ip, QString port, QString username, QString password,
                             QComboBox* urlToCheck, QString settings, QWidget *parent) :
        indexDisp(new QLabel(index, this)),
        ipLabel(new QLabel(ip, this)),
        portLabel(new QLabel(port, this)),
        usernameLabel(new QLabel(username, this)),
        passwordLabel(new QLabel(password, this)),
        proxyOn(QPixmap::fromImage(QImage(file_paths::PROXYON_IMG).scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation))),
        proxyOff(QPixmap::fromImage(QImage(file_paths::PROXYOFF_IMG).scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation))),
        proxyNeutral(QPixmap::fromImage(QImage(file_paths::PROXYNEUTRAL_IMG).scaled(16, 16, Qt::KeepAspectRatio, Qt::SmoothTransformation))),
        pc(index.toStdString()),
        urlCombo(urlToCheck),
        QWidget(parent) {

    // Set the object name and height
    setContentsMargins(2, 2, 2, 2);

    // Give each QLabel a fixed size
    indexDisp->setFixedWidth(20);
    indexDisp->setObjectName(settings);
    ipLabel->setFixedWidth(110);
    ipLabel->setObjectName(settings);
    portLabel->setFixedWidth(40);
    portLabel->setObjectName(settings);
    usernameLabel->setFixedWidth(80);
    usernameLabel->setObjectName(settings);
    passwordLabel->setFixedWidth(70);
    passwordLabel->setObjectName(settings);

    // Build the status code light on the proxylistitem
    proxyOn.setDevicePixelRatio(2.0);
    proxyOff.setDevicePixelRatio(2.0);
    proxyNeutral.setDevicePixelRatio(2.0);

    // Add all the QWidgets to a horizontal layout
    auto mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(2, 1, 1, 1);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(indexDisp);
    mainLayout->addWidget(ipLabel);
    mainLayout->addWidget(portLabel);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(passwordLabel);
    if (indexDisp->text().toStdString() != "#") {
        statusIMG = new QLabel(this);
        statusIMG->setFixedWidth(16);
        statusIMG->setPixmap(proxyNeutral);
        mainLayout->addWidget(statusIMG);
    } else {
        statusIMG = new QLabel("?", this);
        statusIMG->setFixedWidth(16);
        statusIMG->setObjectName(settings);
        mainLayout->addWidget(statusIMG);
    }
    setLayout(mainLayout);

    // Connect up the proxy list item's return function
    connect(&pc, SIGNAL(returnStatus(int)), this, SLOT(updateStatus(int)));
}

// Function that checks the status of the proxy in the list item
void ProxyListItem::checkStatus() {
    emit proxyCheckStart();
    // Do not run for the header row
    if (indexDisp->text().toStdString() == "#") { return; }

    // Reset the proxy status
    statusIMG->setPixmap(proxyNeutral);

    // Set up a concurrent run of the proxy function
    QFuture<void> future = QtConcurrent::run(&pc, &ProxyChecker::run, supported_sites::WEBSITES.at(urlCombo->currentText().toStdString()).baseURL);
    auto *watcher = new QFutureWatcher<void>(this);
    connect(watcher, SIGNAL(finished()), this, SLOT(proxyEndEmit()));
    connect(watcher, SIGNAL(finished()), watcher, SLOT(deleteLater()));
    watcher->setFuture(future);
}

// Proxy end emitter
void ProxyListItem::proxyEndEmit() { emit proxyCheckEnd(); }

// Function to be
void ProxyListItem::updateStatus(int status) {
    if (status == 1) {
        statusIMG->setPixmap(proxyOn);
    } else {
        statusIMG->setPixmap(proxyOff);
    }
    remove(std::string(QApplication::applicationDirPath().append(file_paths::PROXYCHECK).toStdString() + indexDisp->text().toStdString()).c_str());
}

// Constructor that builds the proxy window
ProxyDisplay::ProxyDisplay(QWidget *parent) :
        proxiesViewTitle(new QLabel("Proxies", this)),
        proxyStatusCheck(new QLabel("Idle.", this)),
        addProxyButton(new ClickableImage(26, 26, 2, file_paths::ADD2_IMG, file_paths::ADD_IMG, this)),
        pasteProxyButton(new ClickableImage(26, 26, 2, file_paths::LOGS2_IMG, file_paths::LOGS_IMG, this)),
        deleteProxyButton(new ClickableImage(26, 26, 2, file_paths::MINUS2_IMG, file_paths::MINUS_IMG, this)),
        refreshProxies(new ClickableCheckableImage(26, 26, 2, file_paths::REFRESH2_IMG, file_paths::REFRESH_IMG,
                                                   file_paths::REFRESH2_IMG, file_paths::REFRESH_IMG,
                                                   file_paths::DISABLEDREFRESH_IMG, this)),
        proxiesListView(new QListWidget(this)),
        websiteToCheck(new QComboBox(this)),
        columnProxies(new ProxyListItem("#", "IP", "PORT", "USERNAME", "PASSWORD", websiteToCheck, "proxiesindexitem", this)),
        QWidget(parent) {

    // Set window properties
    setFixedSize(400, 300);
    setWindowTitle("Proxies");
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this, true);

    // Build the website combobox
    websiteToCheck->addItems(supported_sites::ssStringList);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Create normal layouts
    auto mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(11, 3, 11, 11);
    auto topRow = new QWidget(this);
    auto smallButtonRow = new QHBoxLayout();
    topRow->setLayout(smallButtonRow);
    topRow->setContentsMargins(0, 0, 0, 0);
    smallButtonRow->setContentsMargins(0, 0, 0, 0);

    // Add the widgets to their respective layouts
    proxiesViewTitle->setObjectName("addtask_mediocre_text");
    proxiesViewTitle->setFixedWidth(45);
    proxyStatusCheck->setObjectName("proxiesstatustext");
    proxyStatusCheck->setAlignment(Qt::AlignCenter);
    smallButtonRow->addWidget(proxiesViewTitle);
    smallButtonRow->addWidget(proxyStatusCheck);
    smallButtonRow->addWidget(refreshProxies);
    smallButtonRow->addWidget(websiteToCheck);
    smallButtonRow->addWidget(addProxyButton);
    smallButtonRow->addWidget(pasteProxyButton);
    smallButtonRow->addWidget(deleteProxyButton);
    mainLayout->addWidget(topRow);
    mainLayout->addWidget(columnProxies);

    proxiesListView->setObjectName("profileslistview");
    proxiesListView->setSelectionMode(QAbstractItemView::SingleSelection);
    proxiesListView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    proxiesListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainLayout->addWidget(proxiesListView);

    // Load the proxies from the file
    refresh(0);

    // Finally add the layouts to their parents
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Make the connections
    connect(addProxyButton, SIGNAL(clicked()), this, SLOT(openAddProxy()));
    connect(deleteProxyButton, SIGNAL(clicked()), this, SLOT(deleteProxy()));
    connect(pasteProxyButton, SIGNAL(clicked()), this, SLOT(openPasteProxy()));
}

// Override the proxy display's close event function to emit closed
void ProxyDisplay::closeEvent(QCloseEvent *event) {
    // Make sure a proxy check is not running
    if (threadsOpen != 0) {
        event->ignore();
    } else {
        emit closed();
        QWidget::closeEvent(event);
    }
}

// Opens the add proxy window
void ProxyDisplay::openAddProxy() {
    // Make sure an add proxy window is not already open
    if (addWindOpen) {
        apd->raise();
        apd->setFocus();
        return;
    }
    if (pasteWindOpen) {
        ppw->close();
        pasteWindOpen = false;
    }

    // If not, then build a new add proxy window and change bool value
    apd = new AddProxyDisplay(proxiesListView->count() + 1, refreshProxies);
    apd->show();
    addWindOpen = true;

    // Make necessary connections
    connect(apd, &AddProxyDisplay::closed, [this] () { addWindOpen = false; });
    connect(apd, &AddProxyDisplay::submitted, [this] () {
        // Refresh with the new proxy selected
        refresh(proxiesListView->count());
    });
}

// Opens the paste proxy window
void ProxyDisplay::openPasteProxy() {
    // Make sure a paste proxy window is not already open
    if (pasteWindOpen) {
        ppw->raise();
        ppw->setFocus();
        return;
    }
    if (addWindOpen) {
        apd->close();
        addWindOpen = false;
    }

    // If not, then build a new paste proxy window and change the bool value
    ppw = new ProxyPaster(proxiesListView->count() + 1, refreshProxies);
    ppw->show();
    pasteWindOpen = true;

    // Make necessary connections
    connect(ppw, &ProxyPaster::closed, [this] () { pasteWindOpen = false; });
    connect(ppw, &ProxyPaster::submitted, [this] () {
        // Refresh with the end of the new proxies selected
        refresh(proxiesListView->count());
    });
}

// Refreshes the ProxyDisplay while retaining the selected element
void ProxyDisplay::refresh(int selected) {
    // Clear the proxy display
    proxiesListView->clear();

    // Read in the Proxy Display file and interpret the JSON
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::PROXIES_TXT).toStdString().c_str());
    std::string str;

    // Cycle through each line and read in the JSON object for each IP
    while (getline(filein, str)) {
        if (str.empty()) { continue; }
        const unsigned long indexPos = str.find(" :-: ");
        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(str.substr(indexPos + 5).c_str()).toUtf8());
        QJsonObject jsonObject = jsonDoc.object();

        // Use the JSON object to add a new proxy to the list
        auto lwidgitem = new QListWidgetItem();
        auto newWidgItem = new ProxyListItem(str.substr(0, indexPos).c_str(),
                jsonObject.value("proxyip").toString(),
                jsonObject.value("proxyport").toString(),
                jsonObject.value("proxyusername").toString(),
                jsonObject.value("proxypassword").toString(),
                                             websiteToCheck,
                                             "", proxiesListView);
        lwidgitem->setSizeHint(newWidgItem->sizeHint());
        proxiesListView->addItem(lwidgitem);
        proxiesListView->setItemWidget(lwidgitem, newWidgItem);

        // Make necessary connections
        connect(refreshProxies, SIGNAL(runTask()), newWidgItem, SLOT(checkStatus()));
        connect(refreshProxies, SIGNAL(interrupt()), newWidgItem, SLOT(checkStatus()));
        connect(newWidgItem, &ProxyListItem::proxyCheckStart, [this] () {
            threadsOpen += 1;
            proxyStatusCheck->setText("Running status check...");
            refreshProxies->disable();
        });
        connect(newWidgItem, &ProxyListItem::proxyCheckEnd, [this] () {
            threadsOpen -= 1;
            if (threadsOpen == 0) {
                proxyStatusCheck->setText("Idle.");
                refreshProxies->enable();
            }
        });
    }

    // Close the proxy file
    filein.close();
    // Select the desired integer
    proxiesListView->setCurrentRow(selected + 1);
}

// Deletes the selected proxy in the listview and from the proxies textfile
void ProxyDisplay::deleteProxy() {
    // Make sure that a proxy check is not currently running
    if (!refreshProxies->enabled) { return; }

    // Open both proxy text files
    std::ifstream filein(QApplication::applicationDirPath().append(file_paths::PROXIES_TXT).toStdString().c_str());
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::TEMPPROXIES_TXT).toStdString().c_str());
    std::string str;
    int indices = 0;

    // Cycle through the in file and check for the index to be deleted
    while (getline(filein, str)) {
        if (str.empty()) { continue; }
        // Check if the index of the proxy matches that of the selected one
        const unsigned long indexPos = str.find(" :-: ");
        if (str.substr(0, indexPos) != std::to_string(proxiesListView->currentRow() + 1)) {
            indices++;
            fileout << std::to_string(indices) << str.substr(indexPos) << "\n";
        }
    }

    // Finally, close both files
    filein.close();
    fileout.close();

    // Rename the temporary proxies file to the real one
    rename(QApplication::applicationDirPath().append(file_paths::TEMPPROXIES_TXT).toStdString().c_str(),
           QApplication::applicationDirPath().append(file_paths::PROXIES_TXT).toStdString().c_str());

    // Then refresh with the previous one now selected
    refresh(proxiesListView->currentRow() - 1);
}

// ADD PROXY DISPLAY
// Constructor that builds the Add Proxy window
AddProxyDisplay::AddProxyDisplay(int newIndex, ClickableCheckableImage* refresher, QWidget *parent) :
        refreshButton(refresher),
        index(newIndex),
        proxyIPLabel(new QLabel("IP:", this)),
        proxyIP(new QLineEdit(this)),
        proxyPortLabel(new QLabel("Port:", this)),
        proxyPort(new QLineEdit(this)),
        proxyUsernameLabel(new QLabel("Username:", this)),
        proxyUsername(new QLineEdit(this)),
        proxyPasswordLabel(new QLabel("Password:", this)),
        proxyPassword(new QLineEdit(this)),
        submit(new QPushButton("ADD", this)),
        QWidget(parent) {

    // Set window properties
    setFixedSize(400, 145);
    setWindowTitle("Add New Proxy");
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this, true);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Create the main layout
    auto mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(11, 3, 11, 11);
    auto ipAndPortLayout = new QHBoxLayout();
    auto userLayout = new QHBoxLayout();
    auto passLayout = new QHBoxLayout();

    // Set widget properties
    proxyIPLabel->setObjectName("addtask_mediocre_text");
    proxyIP->setObjectName("addtask_editbox");
    proxyIP->setMinimumHeight(20);
    proxyUsernameLabel->setObjectName("addtask_mediocre_text");
    proxyUsername->setObjectName("addtask_editbox");
    proxyPortLabel->setObjectName("addtask_mediocre_text");
    proxyPort->setObjectName("addtask_editbox");
    proxyPort->setMinimumHeight(20);
    proxyPort->setStyleSheet("margin-right: 5px;");
    proxyPasswordLabel->setObjectName("addtask_mediocre_text");
    proxyPassword->setObjectName("addtask_editbox");
    submit->setObjectName("addtaskbutton");
    submit->setContentsMargins(4, 1, 1, 1);
    submit->setFixedSize(100, 30);

    // Add the widgets to their layouts
    ipAndPortLayout->addWidget(proxyIPLabel);
    ipAndPortLayout->addWidget(proxyIP);
    ipAndPortLayout->addWidget(proxyPortLabel);
    ipAndPortLayout->addWidget(proxyPort);
    ipAndPortLayout->addWidget(submit);
    userLayout->addWidget(proxyUsernameLabel);
    userLayout->addWidget(proxyUsername);
    passLayout->addWidget(proxyPasswordLabel);
    passLayout->addWidget(proxyPassword);
    mainLayout->addLayout(ipAndPortLayout);
    mainLayout->addLayout(userLayout);
    mainLayout->addLayout(passLayout);

    // Finalize layout decisions
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Make final connections
    connect(submit, SIGNAL(clicked()), this, SLOT(createNewProxy()));
}

// Override the close event to emit closed
void AddProxyDisplay::closeEvent(QCloseEvent *event) {
    emit closed();
    QWidget::closeEvent(event);
}

// Function to create a new Proxy in the Proxies file
void AddProxyDisplay::createNewProxy() {
    // Don't allow creating a new proxy if a proxy check is in action
    if (!refreshButton->enabled) { return; }

    // First ensure that there is data in every required field
    if (proxyIP->text().isEmpty()) { proxyIP->setFocus(); return; }
    if (proxyPort->text().isEmpty()) { proxyPort->setFocus(); return; }

    // Open the proxy text file
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::PROXIES_TXT).toStdString().c_str(),
                          std::ios_base::app | std::ios_base::out);

    // Append a new proxy to the file in the given format
    fileout << std::to_string(index) << R"( :-: {"proxyip":")" << proxyIP->text().toStdString() <<
            R"(","proxyport":")" << proxyPort->text().toStdString() << R"(","proxyusername":")" <<
            proxyUsername->text().toStdString() << R"(","proxypassword":")" << proxyPassword->text().toStdString() <<
            R"("})" << "\n";

    // Close the outfile
    fileout.close();

    // Close the window and emit submit
    emit submitted();
    close();
}

// PROXY PASTER DISPLAY CLASS
// Window which displays a text edit to paste in proxies.
ProxyPaster::ProxyPaster(int newIndex, ClickableCheckableImage* refresher, QWidget* parent) :
        refreshButton(refresher),
        index(newIndex),
        proxies(new QTextEdit(this)),
        pasteFormat(new QLabel("ip:port", this)),
        pasteFormat2(new QLabel(":username:password", this)),
        submit(new QPushButton("SUBMIT", this)),
        QWidget(parent) {

    // Set window properties
    setFixedSize(275, 275);
    setWindowTitle("Paste In Proxies");
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Create the main layout
    auto mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(11, 3, 11, 11);
    auto submitRow = new QHBoxLayout;
    submitRow->setSpacing(0);

    // Set widget properties
    proxies->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    proxies->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pasteFormat2->setObjectName("addtask_mediocre_text");
    submit->setObjectName("addtaskbutton");
    submit->setFixedSize(70, 30);

    // Add widgets to rows
    submitRow->addSpacing(5);
    submitRow->addWidget(pasteFormat);
    submitRow->addWidget(pasteFormat2);
    submitRow->addStretch();
    submitRow->addWidget(submit);
    mainLayout->addWidget(proxies);
    mainLayout->addLayout(submitRow);

    // Set the layout
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Connect submit button
    connect(submit, SIGNAL(clicked()), this, SLOT(createNewProxies()));
}

// Override the paste proxy close event
void ProxyPaster::closeEvent(QCloseEvent* event) {
    emit closed();
    QWidget::closeEvent(event);
}

// Submits the proxy information and writes it to the proxy file
void ProxyPaster::createNewProxies() {
    // First make sure that there is not a proxy check going on
    if (!refreshButton->enabled) { return; }
    // First ensure that there is data in the proxies window
    if (proxies->toPlainText().isEmpty()) { close(); return; }

    // Open the proxy text file
    std::ofstream fileout(QApplication::applicationDirPath().append(file_paths::PROXIES_TXT).toStdString().c_str(),
                          std::ios_base::app | std::ios_base::out);

    // Now iterate through the lines in the proxies
    QTextDocument *doc = proxies->document();
    QTextBlock block = doc->begin();
    while(block.isValid()) {
        // Need to make sure this is a valid proxy
        std::string toWrite;
        std::string currentline = block.text().toStdString();
        unsigned long substrPos = currentline.find(':');
        // There should be either 2 or 4 substrings between semicolons
        if (substrPos == std::string::npos) {
            // Move on to next block
            block = block.next();
            continue; }
        toWrite.append(std::to_string(index) + R"( :-: {"proxyip":")" + currentline.substr(0, substrPos));
        currentline.erase(0, substrPos + 1);
        substrPos = currentline.find(':');
        // In this case, it is just an IP and PORT, no username and password
        if (substrPos == std::string::npos) {
            toWrite.append(std::string(R"(","proxyport":")") + currentline + R"(","proxyusername":"","proxypassword":""})");
            fileout << toWrite << "\n";
            // Move on to next block
            block = block.next();
            continue;
        }
        toWrite.append(std::string(R"(","proxyport":")") + currentline.substr(0, substrPos));
        currentline.erase(0, substrPos + 1);
        substrPos = currentline.find(':');
        if (substrPos == std::string::npos) {
            // Move on to next block
            block = block.next();
            continue; }
        toWrite.append(std::string(R"(","proxyusername":")") + currentline.substr(0, substrPos));
        currentline.erase(0, substrPos + 1);
        toWrite.append(std::string(R"(","proxypassword":")") + currentline + R"("})");

        std::cout << "3" << std::endl;

        // Now write the line to the file
        fileout << toWrite << "\n";

        // Move on to next block
        block = block.next();
    }
    // Finally close the out file
    fileout.close();

    // Close the window and emit submit
    emit submitted();
    close();
}

// Constructor to build the product parser display
ProductParserDisplay::ProductParserDisplay(QWidget *parent) :
        parsedProductsLabel(new QLabel("Parsed Products: ", this)),
        parsedProducts(new QTextBrowser(this)),
        websiteLabel(new QLabel("Website: ", this)),
        websites(new QComboBox(this)),
        typeLabel(new QLabel("Type: ", this)),
        collectionLabel(new QLabel("Collection ", this)),
        collection(new QCheckBox(this)),
        productLabel(new QLabel("Product ", this)),
        product(new QCheckBox(this)),
        extensionLabel(new QLabel("Extension: ", this)),
        extension(new QLineEdit(this)),
        availabilityFilteringLabel(new QLabel("Availability Filter: ", this)),
        availabilityFiltering(new QCheckBox(this)),
        limitLabel(new QLabel("Limit: ", this)),
        limit(new QLineEdit(this)),
        goButton(new QPushButton("GO", this)),
        QWidget(parent) {

    // Set window properties
    setFixedSize(250, 500);
    setWindowTitle("URL Variant Parser");
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::ClickFocus);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this, true);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Build the main layout and sub layouts
    auto mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(11, 3, 11, 11);

    // Widget horizontal layouts
    auto websiteLayout = new QHBoxLayout;
    auto typeLayout = new QHBoxLayout;
    auto extensionLayout = new QHBoxLayout;
    auto filteringLayout = new QHBoxLayout;
    auto limitLayout = new QHBoxLayout;

    // Set widget properties
    parsedProducts->setReadOnly(true);
    parsedProducts->setObjectName("logs_text");
    parsedProducts->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    parsedProducts->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    parsedProducts->setText("No products parsed yet.");
    websiteLabel->setObjectName("addtask_mediocre_text");
    websites->addItems(supported_sites::ssStringList);
    typeLabel->setObjectName("addtask_mediocre_text");
    typeLabel->setFixedWidth(35);
    collection->setChecked(true);
    extensionLabel->setObjectName("addtask_mediocre_text");
    extension->setObjectName("addtask_editbox");
    availabilityFilteringLabel->setObjectName("addtask_mediocre_text");
    limitLabel->setObjectName("addtask_mediocre_text");
    limitLabel->setFixedWidth(35);
    limit->setObjectName("addtask_editbox");
    limit->setValidator(new QIntValidator(1, 250));
    limit->setText("20");
    limit->setFixedWidth(35);
    goButton->setObjectName("addtaskbutton");
    goButton->setFixedSize(210, 30);

    // Add the widgets to their layouts
    websiteLayout->addWidget(websiteLabel);
    websiteLayout->addWidget(websites);
    mainLayout->addLayout(websiteLayout);
    typeLayout->addStretch();
    typeLayout->addWidget(typeLabel);
    typeLayout->addWidget(collection);
    typeLayout->addWidget(collectionLabel);
    typeLayout->addWidget(product);
    typeLayout->addWidget(productLabel);
    typeLayout->addStretch();
    mainLayout->addLayout(typeLayout);
    extensionLayout->addWidget(extensionLabel);
    extensionLayout->addWidget(extension);
    mainLayout->addLayout(extensionLayout);
    filteringLayout->addStretch();
    filteringLayout->addWidget(availabilityFilteringLabel);
    filteringLayout->addWidget(availabilityFiltering);
    filteringLayout->addSpacing(10);
    filteringLayout->addWidget(limitLabel);
    filteringLayout->addWidget(limit);
    filteringLayout->addStretch();
    mainLayout->addLayout(filteringLayout);
    limitLayout->setContentsMargins(0, 0, 0, 0);
    limitLayout->addStretch();
    limitLayout->addWidget(goButton);
    limitLayout->addStretch();
    mainLayout->addLayout(limitLayout);
    mainLayout->addWidget(parsedProductsLabel);
    mainLayout->addWidget(parsedProducts);

    // Finalize layout decisions
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Make sure that collection and product are not both checked or neither checked
    connect(collection, &QCheckBox::stateChanged, [this] () { product->setChecked(collection->checkState() == 0); } );
    connect(product, &QCheckBox::stateChanged, [this] () { collection->setChecked(product->checkState() == 0); } );
    connect(websites, &QComboBox::currentTextChanged, [this] () {
        if (websites->currentText() == "Kith") {
            availabilityFiltering->setChecked(true);
            availabilityFiltering->setDisabled(true);
        } else {
            availabilityFiltering->setDisabled(false);
        }
    });

    // Connect the go button to the parse product slot
    connect(goButton, SIGNAL(clicked()), this, SLOT(parseProds()));
}

// Override the window close event to emit the closed signal
void ProductParserDisplay::closeEvent(QCloseEvent *event) {
    emit closed();
    QWidget::closeEvent(event);
}

// Uses the information in the lineedits and combobox to get all the models into a products log
void ProductParserDisplay::parseProds() {

    // Make sure all the necessary fields are filled
    if (product->isChecked() && extension->text().isEmpty()) { extension->setFocus(); return; }

    // Create a temporary shopify website handler
    ShopifyWebsiteHandler swh(supported_sites::WEBSITES.at(websites->currentText().toStdString()), "temp");

    // Pull the models from the given page for the specified method
    if (collection->isChecked()) {
        // Pull all the models from the collection page
        swh.getAllModels(extension->text().toStdString(), availabilityFiltering->isChecked(), std::string("?limit=").append(limit->text().toStdString()));
    } else {
        // Pull all the variants from the product page
        swh.getAllModelsProductPage(extension->text().toStdString(), availabilityFiltering->isChecked());
    }

    // Then load the file into the product parsed view
    QFile* productsLog = new QFile(std::string(QApplication::applicationDirPath().append(file_paths::PRODUCTS_LOG).
            toStdString().c_str()).append(supported_sites::WEBSITES.at(websites->currentText().toStdString()).title).
            append("temp.txt").c_str());
    productsLog->open(QIODevice::ReadOnly);
    if (productsLog->exists()) {
        // If the products log is found, then parse their products
        auto logStream = new QTextStream(productsLog);
        parsedProducts->setText(logStream->readAll());
    } else {
        parsedProducts->setText("Error loading product log file.");
    }
}

// MARK: Settings List Item
// Put this in the settings window list to be able to edit the colors of the client.
SettingsListItem::SettingsListItem(const std::string& name, ColorCustomizer* ccobj, QWidget *parent, QString settingsName) :
        variableTitle(new QLabel(name.c_str(), this)),
        cc(ccobj),
        QWidget(parent) {

    // Main layout
    auto mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(1, 1, 1, 1);
    mainLayout->addWidget(variableTitle);

    // Set some properties
    setFixedSize(300, 24);
    setContentsMargins(3, 1, 3, 1);
    setObjectName(settingsName);
    variableTitle->setFixedWidth(150);
    variableTitle->setObjectName(settingsName);

    // Get the value of the object through the color customizer and put it into the qlineedit
    if (variableTitle->text() != "VARIABLE") {
        realVarName = constants::CUSTOMIZEVARS.at(name);
        initialVal = cc->currentColors[realVarName];
        value = new QLineEdit(this);
        value->setText(cc->currentColors[realVarName].c_str());
        value->setFixedWidth(60);
        value->setObjectName("proxieslistedit");

        // Connect the qlineedit's signals to its slots and lambdas
        connect(value, &QLineEdit::editingFinished, [this] () { value->setText(initialVal.c_str()); });
        connect(value, SIGNAL(returnPressed()), this, SLOT(changeVar()));

        mainLayout->addWidget(value);
        // Build the preview of the text as well
        previewValue = new QLabel(this);
        if (variableTitle->text() != "Font") {
            previewValue->setStyleSheet(std::string("background-color: ").append(value->text().toStdString()).append("; border-radius: 2px;").c_str());
            previewValue->setFixedHeight(14);
        } else {
            previewValue->setStyleSheet(std::string("font-family: ").append(value->text().toStdString()).append(";").c_str());
            previewValue->setText("Sample");
            previewValue->setFixedHeight(20);
        }
        mainLayout->addWidget(previewValue);
    } else {
        valueLabel = new QLabel("VALUE", this);
        valueLabel->setObjectName(settingsName);
        valueLabel->setFixedWidth(80);
        mainLayout->addWidget(valueLabel);
        previewLabel = new QLabel("PREVIEW", this);
        previewLabel->setObjectName(settingsName);
        mainLayout->addWidget(previewLabel);
    }

    setLayout(mainLayout);
}

// Resets the variable if its text box is currently selected
void SettingsListItem::resetVar() {
    // If the text edit is not selected, do nothing
    if (!value->hasFocus()) { return; }

    // Otherwise reset the variable and then set the value
    cc->resetValue(realVarName);
    value->setText(cc->currentColors[realVarName].c_str());

    // Update the preview
    updateVar();
}

// Updates the list item with its new value
void SettingsListItem::updateVar() {
    // Update the variable with its new information
    if (variableTitle->text() != "Font") {
        previewValue->setStyleSheet(std::string("background-color: ").append(value->text().toStdString()).append("; border-radius: 2px;").c_str());
    } else {
        previewValue->setStyleSheet(std::string("font-family: ").append(value->text().toStdString()).append(";").c_str());
    }
}

// Changes the list item in the cc to its new value
void SettingsListItem::changeVar() {
    // Get the text from the qlineedit and change the value
    cc->changeValue(realVarName, value->text().toStdString());
    // Now update the preview
    updateVar();
    // Also change the stored value
    initialVal = value->text().toStdString();
}

// MARK: Settings Display
// The window in which you can change client colors and other variables.
SettingsDisplay::SettingsDisplay(QWidget *parent) :
        variableColName(new QLabel("Main Settings: ", this)),
        listColumns(new SettingsListItem("VARIABLE", &cc, this, "proxiesindexitem")),
        variablesList(new QListWidget(this)),
        resetSingleButton(new QPushButton("Reset", this)),
        resetAllButton(new QPushButton("Reset All to Defaults", this)),
        QWidget(parent) {

    // Set window properties
    setFixedSize(330, 300);
    setWindowTitle("Settings");
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_QuitOnClose, false);
    setAttribute(Qt::WA_TranslucentBackground);

    // Create the dark title bar
    dtb = new DarkTitleBar(this);

    // Set the stylesheet for the window
    QFile File(file_paths::STYLESHEET);
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    QFile File2(QApplication::applicationDirPath().append(file_paths::COLORSTYLESHEET).toStdString().c_str());
    File2.open(QFile::ReadOnly);
    QString CStyleSheet = QLatin1String(File2.readAll());
    setStyleSheet(StyleSheet + CStyleSheet);

    // Create external qframe and layouts for dtb
    auto externLayout = new QVBoxLayout();
    externLayout->setContentsMargins(0, 0, 0, 0);
    auto bg = new QFrame(this);
    auto bgLayout = new QVBoxLayout();
    bgLayout->setContentsMargins(0, 0, 0, 0);
    bg->setObjectName("main_window");
    bg->setLayout(bgLayout);
    bgLayout->addWidget(dtb);
    externLayout->addWidget(bg);

    // Set properties of qlabels and other widgets
    variableColName->setObjectName("addtask_mediocre_text");
    variablesList->setObjectName("profileslistview");
    variablesList->setSelectionMode(QAbstractItemView::SingleSelection);
    variablesList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    variablesList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    variablesList->setFixedWidth(306);
    variablesList->setContentsMargins(1, 4, 1, 4);
    variablesList->setSelectionMode(QAbstractItemView::NoSelection);
    variablesList->setFocusPolicy(Qt::NoFocus);
    resetSingleButton->setObjectName("subbutton");
    resetAllButton->setObjectName("subbutton");

    // Build the main layout
    auto mainLayout = new QHBoxLayout;
    mainLayout->setContentsMargins(11, 3, 11, 11);
    auto leftcol = new QVBoxLayout;
    // leftcol->addWidget(variableColName);
    auto rightcol = new QVBoxLayout;
    rightcol->addWidget(listColumns);
    rightcol->addWidget(variablesList);
    auto bottomButtonLayout = new QHBoxLayout;
    bottomButtonLayout->addWidget(resetSingleButton);
    bottomButtonLayout->addSpacing(10);
    bottomButtonLayout->addWidget(resetAllButton);
    rightcol->addStretch();
    rightcol->addLayout(bottomButtonLayout);
    mainLayout->addLayout(leftcol);
    mainLayout->addLayout(rightcol);

    // Set the window's layout
    bgLayout->addLayout(mainLayout);
    setLayout(externLayout);

    // Add all variable names to the list
    for (const auto &i : constants::CUSTOMIZEVARS) {
        auto tempItem = new SettingsListItem(i.first, &cc, this);
        auto tempLWidgItem = new QListWidgetItem();
        tempLWidgItem->setSizeHint(tempItem->sizeHint());
        variablesList->addItem(tempLWidgItem);
        variablesList->setItemWidget(tempLWidgItem, tempItem);

        // Make connections for each widg
        connect(resetSingleButton, SIGNAL(clicked()), tempItem, SLOT(resetVar()));
    }

    // Make necessary connections
    connect(resetAllButton, SIGNAL(clicked()), this, SLOT(resetAll()));
}

// Override the close event to emit a closed signal
void SettingsDisplay::closeEvent(QCloseEvent *event) {
    emit closed();
    QWidget::closeEvent(event);
}

// Resets all the variables to their default states
void SettingsDisplay::resetAll() {

    // Clear the variables list and reload the variables in, having copied over the defaults
    variablesList->clear();
    cc.resetAllValues();
    // Add all variable names to the list
    for (const auto &i : constants::CUSTOMIZEVARS) {
        auto tempItem = new SettingsListItem(i.first, &cc, this);
        auto tempLWidgItem = new QListWidgetItem();
        tempLWidgItem->setSizeHint(tempItem->sizeHint());
        variablesList->addItem(tempLWidgItem);
        variablesList->setItemWidget(tempLWidgItem, tempItem);

        // Make connections for each widg
        connect(resetSingleButton, SIGNAL(clicked()), tempItem, SLOT(resetVar()));
    }
}