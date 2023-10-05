#include "abstractconverter.h"

#include <QDebug>
#include <QScrollArea>
#include <QGridLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFrame>
#include <QSpacerItem>

AbstractConverter::AbstractConverter(QWidget *parent)
    : QWidget{parent}
{
    //FONTS
    //QFont exoFont("Exo Medium", 15);
    //QFont dosisFont("Dosis", 15, QFont::Light);
    //QFont dosisBoldFont("Dosis", 15, QFont::Bold);
    QFont aleoFont("Aleo", 10);
    QFont aleoBoldFont("Aleo", 15);
    //QFont mulishFont("Mulish", 15, QFont::ExtraLight);
    //CREATE THE GRID LAYOUT
    QGridLayout *converterGridLayout = new QGridLayout(this);
    //In which row should output UI start ?
    outputStartingRow = 2;

    //for testing
    //unitList = {"1", "2", "3"};
    unitList = {"1", "2", "3", "4", "5"};
    //unitList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    //unitList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
    //unitList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25"};
    conversionType = "length";

    //Setup converter UI
    AbstractConverter::setFont(aleoFont);
    generateInputSection(converterGridLayout, conversionType, unitList, aleoBoldFont);
    generateOutputSection(converterGridLayout, unitList);

    //test
    qDebug() << "Units after running method: " << unitList;
}

void AbstractConverter::generateInputSection(QGridLayout *converterGridLayout, QString &conversionType, QList<QString> &unitList, QFont &inputFont)
{
    //Test to see if the function runs and recognizes the units
    qDebug() << "Units when running method: "<< unitList;

    //Setup layout inside the scrollArea
    converterGridLayout->setContentsMargins(64, 32, 64, 32);
    converterGridLayout->setHorizontalSpacing(64);
    converterGridLayout->setVerticalSpacing(16);
    converterGridLayout->setColumnStretch(0,2);
    converterGridLayout->setColumnStretch(1,1);
    converterGridLayout->setRowMinimumHeight(1, 16);
    setLayout(converterGridLayout);

    //Generate user input section on the top part of the layout
    QLineEdit *inputLineEdit = new QLineEdit(this);
    inputLineEdit->setFont(inputFont);
    inputLineEdit->setPlaceholderText("Enter " + conversionType.toUpper() + "...");
    inputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
    inputLineEdit->setClearButtonEnabled(true);
    QComboBox *unitComboBox = new QComboBox(this);
    unitComboBox->setFont(inputFont);
    unitComboBox->addItems(unitList);

    //Generates a line that seperates input & output section
    QFrame *lineFrame = new QFrame(this);
    lineFrame->setFrameShape(QFrame::HLine);
    lineFrame->setFrameShadow(QFrame::Sunken);

    //Add all of the above to the grid layout
    converterGridLayout->addWidget(inputLineEdit, 0, 0);
    converterGridLayout->addWidget(unitComboBox, 0, 1);
    converterGridLayout->addWidget(lineFrame, 1, 0, 1, 2);

}

void AbstractConverter::generateOutputSection(QGridLayout *converterGridLayout, QList<QString> &unitList){

    //Generates converted values inside lineEdits, below the use input section
    for(int row = outputStartingRow; row < (unitList.count() + outputStartingRow); row++){
        QLineEdit *outputLineEdit = new QLineEdit(this);
        outputLineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        outputLineEdit->setPlaceholderText(unitList.at(row - outputStartingRow));
        converterGridLayout->addWidget(outputLineEdit, row, 0);

        //Create a spacer at the end of the button generation
        if (row >= (unitList.count() + outputStartingRow - 1)) {
            QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            converterGridLayout->addItem(verticalSpacer, row + 1, 0);
        }
    }

    //Generates unit buttons which can be clicked, right next to their value lineEdits.
    for(int row = outputStartingRow; row < (unitList.count() + outputStartingRow); row++){
        QPushButton *unitPushButton = new QPushButton(unitList.at(row - outputStartingRow), this);
        converterGridLayout->addWidget(unitPushButton, row, 1);
    }
}
