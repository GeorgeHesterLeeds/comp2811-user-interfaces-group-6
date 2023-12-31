#ifndef FEEDPREWINDOW_H
#define FEEDPREWINDOW_H

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

class FeedPreWindow : public QWidget
{
    Q_OBJECT

  public:
    FeedPreWindow(QWidget* parent = nullptr);

  private:
    Header* header;
    QScrollArea* scroll_area;
    QWidget* scroll_area_widget;
    QBoxLayout* scroll_area_layout;
    QVector<PostBlank> blanks;
    QVector<QFrame*> frames;
    QVector<QVideoWidget*> frame_video_widgets;

  signals:
    void currentWindowUpdated(Window to, Window from);

  protected:
    void paintPosts();

    void resizePostBlanks(int parent_width, int parent_height);
    void resizeScrollArea(int parent_width, int parent_height);

    void paintEvent(QPaintEvent*) override;
    void resizeEvent(QResizeEvent* event) override;
};

#endif // FEEDPREWINDOW_H
