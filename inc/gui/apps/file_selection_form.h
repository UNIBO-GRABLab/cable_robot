/**
 * @file file_selection_form.h
 * @author Simone Comari
 * @date 11 Feb 2020
 * @brief This file includes the implementation of an input form to select a file within
 * the joints pvt interface.
 */

#ifndef CABLE_ROBOT_JOINTS_PVT_INPUT_FORM_H
#define CABLE_ROBOT_JOINTS_PVT_INPUT_FORM_H

#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

#include "easylogging++.h"

namespace Ui {
class FileSelectionForm;
}

/**
 * @brief The implementation of a generic file selection form.
 */
class FileSelectionForm: public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief Full constructor.
   * @param parent An optional parent widget.
   * @param[in] num Progressive number of input form.
   */
  explicit FileSelectionForm(QWidget* parent = nullptr, const int num = 0);
  ~FileSelectionForm();

  /**
   * @brief Check if a file selection is present, i.e. lineEdit contains a valid filepath.
   * @return _True_ if a file selection is present, _False_ otherwise.
   */
  bool isInputEmpty() const;
  /**
   * @brief Get location of selected file, i.e. its filepath.
   * @return Selected file location.
   */
  QString getFilepath() const;

 signals:
  /**
   * @brief parentDirChanged
   * @param parent_dir
   */
  void parentDirChanged(const QString& parent_dir) const;

 public slots:
  /**
   * @brief setParentDirectory
   * @param parent_dir
   */
  void setParentDirectory(const QString& parent_dir) { parent_dir_ = parent_dir; }

 private slots:
  void on_pushButton_fileSelection_clicked();

 private:
  Ui::FileSelectionForm* ui;

  QString parent_dir_ = "../..";
};

#endif // CABLE_ROBOT_JOINTS_PVT_INPUT_FORM_H
