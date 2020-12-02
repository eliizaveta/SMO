#include "stepmode.h"
#include "ui_stepmode.h"

StepMode::StepMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StepMode) {
    ui->setupUi(this);
}

StepMode::~StepMode() {
    delete ui;
}

void StepMode::setInterp(Andreeva_smo::Interpreter *value) {
    interpreter = value;
}

void StepMode::refreshScene() {

    currentStep = 0;
    ui->textTime->setText("0");
    ui->textStep->setText("0");
    ui->textAllSteps->setText("0");
    ui->textBrowserMessages->clear();
    ui->tableBuffers->clear();
    ui->tableDevices->clear();
}

void StepMode::prepareScene() {

    if (interpreter->getSteps().size() <= 0)
        return;

    const int columnAmountSrc = 2;

    ui->textAllSteps->setText(std::to_string(interpreter->getSteps().size()).c_str());

    ui->tableBuffers->setRowCount(interpreter->getBuffersAmount());
    ui->tableBuffers->setColumnCount(columnAmountSrc);
    ui->tableBuffers->setHorizontalHeaderLabels(QStringList() << "State"<< "Request");
    for (int i=0; i < interpreter->getBuffersAmount(); i++) {
        ui->tableBuffers->setVerticalHeaderItem(i, new QTableWidgetItem(("Buffer " + std::to_string(i+1)).c_str()));
    }

    ui->tableDevices->setRowCount(interpreter->getDevicesAmount());
    ui->tableDevices->setColumnCount(columnAmountSrc);
    ui->tableDevices->setHorizontalHeaderLabels(QStringList() << "State"<< "Request");
    for (int i=0; i < interpreter->getDevicesAmount(); i++) {
        ui->tableDevices->setVerticalHeaderItem(i, new QTableWidgetItem(("Device " + std::to_string(i+1)).c_str()));
    }
}

void StepMode::on_buttonRefresh_clicked() {

    refreshScene();
    prepareScene();
}

void StepMode::on_buttonNext_clicked() {

    if (currentStep + 1 >= interpreter->getSteps().size())
        return;
    if (currentStep < 0){
        currentStep++;
        return;
    }

    currentStep++;

    const std::string free = "Free";
    const std::string busy = "Busy";

    Andreeva_smo::Interpreter::Archive stepModel = interpreter->getSteps().at(currentStep);

    ui->textBrowserMessages->setText(stepModel.message.c_str());
    ui->textTime->setText(std::to_string(stepModel.currentTime).c_str());
    ui->textStep->setText(std::to_string(currentStep).c_str());

    for (int i=0; i < ui->tableBuffers->rowCount(); i++) {
        if (stepModel.buffers.at(i) == stepModel.EMPTY) {
            ui->tableBuffers->setItem(i, 0, new QTableWidgetItem(free.c_str()));
            ui->tableBuffers->setItem(i, 1, new QTableWidgetItem("-"));
        } else {
            ui->tableBuffers->setItem(i, 0, new QTableWidgetItem(busy.c_str()));
            ui->tableBuffers->setItem(i, 1, new QTableWidgetItem(stepModel.buffers.at(i).c_str()));
        }
    }

    for (int i=0; i < ui->tableDevices->rowCount(); i++) {
        if (stepModel.devices.at(i) == stepModel.EMPTY) {
            ui->tableDevices->setItem(i, 0, new QTableWidgetItem(free.c_str()));
            ui->tableDevices->setItem(i, 1, new QTableWidgetItem("-"));
        } else {
            ui->tableDevices->setItem(i, 0, new QTableWidgetItem(busy.c_str()));
            ui->tableDevices->setItem(i, 1, new QTableWidgetItem(stepModel.devices.at(i).c_str()));
        }
    }
}

void StepMode::on_buttonBack_clicked() {

    if (currentStep <= 0)
        return;
    if (currentStep > interpreter->getSteps().size()) {
        currentStep--;
        return;
    }

    currentStep--;

    const std::string free = "Free";
    const std::string busy = "Busy";

    Andreeva_smo::Interpreter::Archive stepModel = interpreter->getSteps().at(currentStep);

    ui->textBrowserMessages->setText(stepModel.message.c_str());
    ui->textTime->setText(std::to_string(stepModel.currentTime).c_str());
    ui->textStep->setText(std::to_string(currentStep).c_str());

    for (int i=0; i < ui->tableBuffers->rowCount(); i++) {
        if (stepModel.buffers.at(i) == stepModel.EMPTY) {
            ui->tableBuffers->setItem(i, 0, new QTableWidgetItem(free.c_str()));
            ui->tableBuffers->setItem(i, 1, new QTableWidgetItem("-"));
        } else {
            ui->tableBuffers->setItem(i, 0, new QTableWidgetItem(busy.c_str()));
            ui->tableBuffers->setItem(i, 1, new QTableWidgetItem(stepModel.buffers.at(i).c_str()));
        }
    }

    for (int i=0; i < ui->tableDevices->rowCount(); i++) {
        if (stepModel.devices.at(i) == stepModel.EMPTY) {
            ui->tableDevices->setItem(i, 0, new QTableWidgetItem(free.c_str()));
            ui->tableDevices->setItem(i, 1, new QTableWidgetItem("-"));
        } else {
            ui->tableDevices->setItem(i, 0, new QTableWidgetItem(busy.c_str()));
            ui->tableDevices->setItem(i, 1, new QTableWidgetItem(stepModel.devices.at(i).c_str()));
        }
    }
}
