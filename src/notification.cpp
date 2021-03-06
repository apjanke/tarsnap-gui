#include "notification.h"

#include <QCoreApplication>
#include <QSettings>

Notification::Notification(QSystemTrayIcon *parent) : QSystemTrayIcon(parent)
{
    setIcon(QIcon(":/icons/tarsnap-icon-big.png"));
}

void Notification::displayNotification(QString message)
{
    QSettings settings;
    if(settings.value("app/notifications", true).toBool()
       && isSystemTrayAvailable())
    {
        // Strip HTML tags
        QString messagePlainText = message.remove(QRegExp("<[^>]*>"));
        // Display message
        show();
        showMessage(QCoreApplication::instance()->applicationName(),
                    messagePlainText);
    }
}
