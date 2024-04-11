//
// Created by User on 11.04.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreatePointsTabDialog.h" resolved

#include "createpointstabdialog.h"
#include "ui_CreatePointsTabDialog.h"


CreatePointsTabDialog::CreatePointsTabDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::CreatePointsTabDialog) {
    ui->setupUi(this);
}

CreatePointsTabDialog::~CreatePointsTabDialog() {
    delete ui;
}
