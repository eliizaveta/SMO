#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    Andreeva_smo::Interpreter *interpreter = new Andreeva_smo::Interpreter();

    configure = new Configure();
    configure->init(interpreter);

    autoMode = new AutoMode();
    autoMode->setInterp(interpreter);

    stepMode = new StepMode();
    stepMode->setInterp(interpreter);

    ui->tabWidget->addTab(configure->topLevelWidget(), "Init");
    ui->tabWidget->addTab(autoMode->topLevelWidget(), "Auto mode");
    ui->tabWidget->addTab(stepMode->topLevelWidget(), "Step mode");
}

MainWindow::~MainWindow() { delete ui; }
