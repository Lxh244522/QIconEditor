#include "iconeditor.h"
#include "ui_iconeditor.h"
#include <QtWidgets>

IconEditor::IconEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IconEditor)
{
    ui->setupUi(this);

    editor = new Icon();

    setCentralWidget(editor);
    createAction();

}

IconEditor::~IconEditor()
{
    delete ui;
}

void IconEditor::iconColor()
{
    QColor color = QColorDialog::getColor(editor->penColor(), this, tr("IconColor"));

    if (!color.isValid()) {
        return;
    }

    editor->setPenColor(color);
    updateColor(color);
}

void IconEditor::updateColor(QColor &curColor)
{
    QPixmap pix(16, 16);
    pix.fill(curColor);
    colorAction->setIcon(pix);
}

void IconEditor::createAction()
{
    QPixmap pix(16, 16);
    pix.fill(Qt::black);
    colorAction = new QAction(pix, tr("&Color..."), this);
    connect(colorAction, &QAction::triggered, this, &IconEditor::iconColor);

    ui->menu_Edit->addAction(colorAction);
    ui->fileToolBar->addSeparator();
    ui->fileToolBar->addAction(colorAction);

    comZoom = new QComboBox(ui->zoomToolBar);
    ui->zoomToolBar->addWidget(comZoom);
}
