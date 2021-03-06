#ifndef COREAPPLICATION_H
#define COREAPPLICATION_H

#include "notification.h"
#include "persistentmodel/journal.h"
#include "taskmanager.h"
#include "widgets/mainwindow.h"

#include <QApplication>
#include <QObject>
#include <QSettings>

/*!
 * \ingroup misc
 * \brief the CoreApplication is a QApplication which launches the MainWindow,
 * SetupWindow (if applicable), and manages background tasks.
 */
class CoreApplication : public QApplication
{
    Q_OBJECT

public:
    //! Constructor.
    CoreApplication(int &argc, char **argv);
    ~CoreApplication();

    //! Parses command-line args.
    void parseArgs();
    //! Initializes the QSettings, Translator, PersistentStore, and launches
    //! the Setup wizard (if necessary).
    bool initialize();

public slots:
    //! Removes the MainWindow (if it exists), resets the PersistentStore
    //! and app Settings, then runs initialize().  Used as a preliminary
    //! step before the SetupWizard.
    bool reinit();
    //! Creates a MainWindow.
    void showMainWindow();

private:
    MainWindow * _mainWindow;
    Notification _notification;
    TaskManager  _taskManager;
    QThread      _managerThread;
    Journal      _journal;
    bool         _jobsOption;
    QString      _appDataDir;
};

#endif // COREAPPLICATION_H
