#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QBoxLayout>
#include <QComboBox>
#include <QString>
#include <QRect>
#include <QStyleOption>
#include <QPainter>
#include <QResizeEvent>
#include <QSlider>

#include "header.h"
#include "settingshandler.h"
#include "displaymode.h"
#include "window.h"

class SettingsWindow : public QWidget
{
    Q_OBJECT

  public:
    SettingsWindow(QWidget* parent = nullptr);

  signals:
    void currentWindowUpdated(Window to, Window from);
    void displayModeUpdated(DisplayMode display_mode);
    void fontSizeScaleUpdated(double scale);

  protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // SETTINGSWINDOW_H
