#ifndef AUTOMODE_H
#define AUTOMODE_H

#include <QWidget>

#include "interpreter.h"
#include "ui_automode.h"

namespace Ui { class AutoMode; }

class AutoMode : public QWidget {
    Q_OBJECT

public:

    explicit AutoMode(QWidget *parent = nullptr);
    ~AutoMode();
    void setInterp(Andreeva_smo::Interpreter *value);
    void interpretation();

private slots:

    void on_buttonRefresh_clicked();

private:

    Ui::AutoMode *ui;
    Andreeva_smo::Interpreter *interpreter;

};

#endif
