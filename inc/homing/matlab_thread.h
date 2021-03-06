/**
 * @file matlab_thread.h
 * @author Simone Comari
 * @date 11 Mar 2019
 * @brief This file includes a Qt thread where to run a Matlab script.
 */

#ifndef CABLE_ROBOT_MATLAB_THREAD_H
#define CABLE_ROBOT_MATLAB_THREAD_H

#include <QFileInfo>
#include <QThread>

#include "grabcommon.h"

/**
 * @brief A thread class to run a Matlab script.
 */
class MatlabThread: public QThread
{
  Q_OBJECT
 public:
  /**
   * @brief MatlabThread default constructor.
   * @param[in] parent The parent Qt object, from which the new thread is forked.
   */
  MatlabThread(QObject* parent) : QThread(parent) {}
  /**
   * @brief MatlabThread
   * @param[in] parent The parent Qt object, from which the new thread is forked.
   * @param[in] script_loc The location of the Matlab script.
   */
  MatlabThread(QObject* parent, const QString& script_loc)
    : QThread(parent), script_loc_(script_loc)
  {}

  /**
   * @brief Set the location of the Matlab script.
   * @param[in] script_loc The location of the Matlab script.
   */
  void SetMatlabScriptLoc(const QString& script_loc) { script_loc_ = script_loc; }

 private:
  QString script_loc_;

  void run() override;

 signals:
  /**
   * @brief Results ready notice.
   */
  void resultsReady() const;
  /**
   * @brief Signal including a message to any QConsole, for instance a QTextBrowser.
   */
  void printToQConsole(const QString&) const;
};

#endif // CABLE_ROBOT_MATLAB_THREAD_H
