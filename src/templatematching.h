#ifndef TEMPLATEMATCHINGUI_H
#define TEMPLATEMATCHINGUI_H

#include <QDialog>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtCore/QDebug>

#include "templatematchingopencv.h"

namespace Ui {
class TemplateMatching;
}

class TemplateMatching : public QDialog
{
    Q_OBJECT

public:
    explicit TemplateMatching(QWidget *parent = 0);
    ~TemplateMatching();

protected:
    /**
     * @brief Find the location of move click in the left graphic view and find the corresponding point (patch in the right side)
     * @details [long description]
     * 
     */
    void mousePressEvent(QMouseEvent *);

private slots:
    /**
     * @brief Load the left image inside the left graphic view and consequently in left graphic scene
     */
    void on_pushButtonLeftImage_clicked();

    /**
     * @brief Load the right image inside the right graphic view and consequently in right graphic scene
     */

    void on_pushButtonRightImage_clicked();

private:
    Ui::TemplateMatching *ui;
    QGraphicsView *graphicsViewLeftImage; /**< Graphic view for loading the left image */
    QGraphicsView *graphicsViewRightImage; /**< Graphic view for loading the right image */
    QGraphicsScene *graphicSceneLeftImage; /**< Graphic scene for loading the left image */
    QGraphicsScene *graphicSceneRightImage; /**< Graphic view for loading the right image */
    QGraphicsPixmapItem *leftPixmap; /**< Pointer to the left pixmap (left image) inside the left graphic scene */
    QGraphicsPixmapItem *rightPixmap; /**< Pointer to the right pixmap (right image) inside the right graphic scene */
    QGraphicsRectItem *leftPatch; /**< Pointer to the left rect (blue rectangle around the selected patch) inside the left graphic scene */
    QGraphicsRectItem *rightPatch; /**< Pointer to the right rect (green rectangle around the selected patch) inside the right graphic scene */
    int initilPatchSize; /**< The initial value for patch size */
    const int padSizeGraphicScene; /**< The pad size between the each graphicness and its image */
    const int padSizeGraphicView; /**< The pad size between the graphic view and mouse click */
    TemplateMatchingOpenCV templateMatcher; /**< Object of TemplateMatchingOpenCV class for finding the corresponding template by using the OpenCV implementation */

    /**
     * @brief Remove the both left and right rectangles indicator around the selected patches
     */
    void removeRectItemsFromScene();
};

#endif // TEMPLATEMATCHING_H
