#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QMainWindow>
#include <QComboBox>
#include "icon.h"

namespace Ui {
class IconEditor;
}

class IconEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconEditor(QWidget *parent = 0);
    ~IconEditor();

private slots:
    void iconColor();

private:
    void updateColor(QColor &curColor);
    void createAction();

private:
    Ui::IconEditor *ui;
    Icon *editor;
    QAction *colorAction;

    QComboBox *comZoom;
};

#endif // ICONEDITOR_H
