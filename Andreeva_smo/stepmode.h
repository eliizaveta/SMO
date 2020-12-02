#ifndef STEPMODE_H
#define STEPMODE_H

#include <QWidget>
#include <interpreter.h>

namespace Ui { class StepMode; }

class StepMode : public QWidget {
    Q_OBJECT

public:

    explicit StepMode(QWidget *parent = nullptr);
    ~StepMode();
    void setInterp(Andreeva_smo::Interpreter *value);

private slots:

    void on_buttonRefresh_clicked();
    void on_buttonNext_clicked();
    void on_buttonBack_clicked();

private:

    int currentStep;
    void refreshScene();
    void prepareScene();
    Ui::StepMode *ui;
    Andreeva_smo::Interpreter *interpreter;

};

#endif
