#include "PictureWidget.h"
#include <QSizePolicy>
#include <QDebug>

PictureWidget::PictureWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    _scaledModel = Qt::KeepAspectRatio;
    initWidget();
    initPictureInfo();
}

PictureWidget::~PictureWidget()
{

}

void PictureWidget::initWidget()
{
    _layoutMain= new QVBoxLayout(this);
    _layoutMain->setSpacing(0);
    _layoutMain->setMargin(0);

    _labelPhoto = new QLabel;
    _labelPhoto->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    _labelPhoto->setMinimumSize(800,600);
    _labelPhoto->setAlignment(Qt::AlignCenter);
    _labelPhoto->setStyleSheet("background:#000000");
    _layoutMain->addWidget(_labelPhoto);
}

void PictureWidget::initPictureInfo()
{
    _picture = new QPixmap;
    QPixmapCache::setCacheLimit(1);
}

void PictureWidget::showPicture(QString& picturePath)
{
    bool isOK = _picture->load(picturePath);
    if(isOK)
    {
         *_picture = _picture->scaled(_widgetWidth,_widgetHeight,_scaledModel,Qt::SmoothTransformation);
        _labelPhoto->setPixmap(*_picture);
    }
}

void PictureWidget::resizeEvent(QResizeEvent *event)
{
    _widgetWidth = this->width();
    _widgetHeight = this->height();
    event->ignore();
}

void PictureWidget::setScaledMode(int scaledModel)
{
    if(scaledModel >= 0 && scaledModel <= 2)
        _scaledModel = static_cast<Qt::AspectRatioMode>(scaledModel);
}
