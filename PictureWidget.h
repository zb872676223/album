#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPixmapCache>
#include <QResizeEvent>

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    PictureWidget(QWidget *parent = nullptr);
    ~PictureWidget();
    void showPicture( QString& picturePath);

    void setScaledMode(int scaledModel);

protected:
    void resizeEvent(QResizeEvent *event);
private:
    QLabel* _labelPhoto;
    QVBoxLayout* _layoutMain;
    QPixmap* _picture;
    int _widgetWidth, _widgetHeight;
    Qt::AspectRatioMode _scaledModel;
private:
    void initWidget();
    void initPictureInfo();

};

#endif // PICTUREWIDGET_H
