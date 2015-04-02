#ifndef TEMPLATEMATCHINGUI_H
#define TEMPLATEMATCHINGUI_H

#include <QDialog>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtCore/QDebug>

#include "templatematchingopencv.h"

namespace Ui {
class TemplateMatchingUI;
}

class TemplateMatchingUI : public QDialog
{
    Q_OBJECT

public:
    explicit TemplateMatchingUI(QWidget *parent = 0);
    ~TemplateMatchingUI();

protected:
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_pushButtonLeftImage_clicked();

    void on_pushButtonRightImage_clicked();

private:
    Ui::TemplateMatchingUI *ui;
    QGraphicsView *graphicsViewLeftImage;
    QGraphicsView *graphicsViewRightImage;
    QGraphicsScene *graphicSceneLeftImage;
    QGraphicsScene *graphicSceneRightImage;
    QGraphicsPixmapItem *leftPixmap;
    QGraphicsPixmapItem *rightPixmap;
    QGraphicsRectItem *leftPatch;
    QGraphicsRectItem *rightPatch;
    TemplateMatchingOpenCV templateMatcher; 
};

#endif // TEMPLATEMATCHINGUI_H
