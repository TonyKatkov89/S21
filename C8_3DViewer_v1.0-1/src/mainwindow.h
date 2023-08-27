#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#ifdef __cplusplus
extern "C" {
#endif

#include "objreader/transform.h"

#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  coords_t *arrayOfCoords;
  int **arrayOfFaces;
  int *fElementsCount;
  int vCount = 0;
  int fCount = 0;

  void dragEnterEvent(QDragEnterEvent *e);
  void dropEvent(QDropEvent *e);
  void parse3DOBJ(QString filename);
  void workTimer(QString filepath);

 public slots:
  void makeGIF();

 private slots:
  void on_actionOpen_triggered();

  void on_actionSave_as_Picture_triggered();

  void on_BBackground_clicked();

  void on_rotateX_valueChanged(double arg1);

  void on_rotateY_valueChanged(double arg1);

  void on_rotateZ_valueChanged(double arg1);

  void on_scaleSB_valueChanged(double arg1);

  void on_moveX_valueChanged(double arg1);

  void on_moveY_valueChanged(double arg1);

  void on_moveZ_valueChanged(double arg1);

  void on_vSize_valueChanged(double arg1);

  void on_vNone_toggled(bool checked);

  void on_vCircle_toggled(bool checked);

  void on_vSquare_toggled(bool checked);

  void on_BBackgroundV_clicked();

  void on_eSolid_toggled(bool checked);

  void on_eDashed_toggled(bool checked);

  void on_eWidth_valueChanged(double arg1);

  void on_BBackgroundE_clicked();

  void on_pParallel_toggled(bool checked);

  void on_pCentral_toggled(bool checked);

  void on_actionExport_to_GIF_triggered();

  void on_actionSave_Settings_triggered();

  void on_actionLoad_Settings_triggered();

  void on_actionReset_Settings_triggered();

  void on_action_4_triggered();

 private:
  Ui::MainWindow *ui;
  bool isTimerReady = true;
};
#endif  // MAINWINDOW_H
