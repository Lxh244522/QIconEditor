#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QMainWindow>

namespace Ui {
class IconEditor;
}

class IconEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit IconEditor(QWidget *parent = 0);
    ~IconEditor();

private:
    Ui::IconEditor *ui;
};

#endif // ICONEDITOR_H
