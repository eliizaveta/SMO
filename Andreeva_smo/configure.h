#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QWidget>
#include <QErrorMessage>

#include "controller.h"

namespace Ui { class Configure; }

class Configure : public QWidget {
    Q_OBJECT

public:

    explicit Configure(QWidget *parent = nullptr);
    ~Configure();
    void init(Andreeva_smo::Interpreter *value);

private slots:

    void on_buttonConfigure_clicked();

private:

    Ui::Configure *ui;
    Andreeva_smo::Controller controller;
    Andreeva_smo::Interpreter *interpreter;
};

#endif
