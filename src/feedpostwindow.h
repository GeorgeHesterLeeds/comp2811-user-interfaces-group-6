#ifndef FEEDPOSTWINDOW_H
#define FEEDPOSTWINDOW_H

#include <QWidget>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QVideoWidget>
#include <QUrl>
#include <QBoxLayout>
#include <QScrollArea>
#include <QVector>
#include <QResizeEvent>
#include <QMediaPlaylist>
#include <QRectF>
#include <QString>

#include "window.h"
#include "header.h"
#include "post.h"
#include "store.h"
#include "frame.h"

class FeedPostWindow : public QWidget
{
    Q_OBJECT

  public:
    FeedPostWindow(QWidget* parent = nullptr);

  private:
    Header* header;
    QScrollArea* scroll_area;
    QWidget* scroll_area_widget;
    QBoxLayout* scroll_area_layout;
    QVector<PostUi> posts;
    QVector<QFrame*> frames;
    QVector<QVideoWidget*> frame_video_widgets;

  signals:
    void currentWindowUpdated(Window to, Window from);

  protected:
    void paintPosts();

    void resizeFrameVideoWidget(int parent_width,
                                int parent_height,
                                QFrame* frame,
                                QVideoWidget* video_widget);
    void resizePosts(int parent_width, int parent_height);
    void resizeScrollArea(int parent_width, int parent_height);

    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent* event) override;
};

#endif // FEEDPOSTWINDOW_H
