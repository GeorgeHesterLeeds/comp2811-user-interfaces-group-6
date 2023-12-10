#include "capturewindow.h"

CaptureWindow::CaptureWindow(QWidget* parent)
  : QWidget(parent)
{
    QBoxLayout* box_layout =
      new QBoxLayout(QBoxLayout::Direction::TopToBottom, this);
    box_layout->setMargin(0);
    box_layout->setSpacing(0);
    this->setLayout(box_layout);

    Header* header = new Header(this);
    box_layout->addWidget(header);

    QList<QCameraInfo> camera_info_list = QCameraInfo::availableCameras();

    if (camera_info_list.length() > 0)
    {
        QCamera* camera = new QCamera(camera_info_list.at(0));

        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsView* view = new QGraphicsView();
        view->setScene(scene);

        QCameraViewfinder* viewfinder = new QCameraViewfinder();
        viewfinder->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
        camera->setViewfinder(viewfinder);

        view->setViewport(viewfinder);
        box_layout->addWidget(view);

        camera->start();
        view->show();
    };
};

void
CaptureWindow::paintEvent(QPaintEvent*)
{
    QStyleOption style_option;
    style_option.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &style_option, &painter, this);
};