#ifndef ARCHIVELISTWIDGETITEM_H
#define ARCHIVELISTWIDGETITEM_H

#include "taskmanager.h"
#include "ui_archivelistwidgetitem.h"

#include <QListWidgetItem>
#include <QObject>

/*!
 * \ingroup widgets-specialized
 * \brief The ArchiveListWidgetItem is a QListWidgetItem which
 * displays information about an archive.
 */
class ArchiveListWidgetItem : public QObject, public QListWidgetItem
{
    Q_OBJECT

public:
    //! Constructor.
    //! \param archive: pointer to the archive to display.
    explicit ArchiveListWidgetItem(ArchivePtr archive);
    ~ArchiveListWidgetItem();

    //! Returns a widget with a graphical representation of this archive.
    QWidget *widget();

    //! Returns a pointer to the archive.
    ArchivePtr archive() const;

    //! Indicate that this archive is scheduled for deletion.
    void setDisabled();
    //! Returns whether this archive is scheduled for deletion.
    bool isDisabled();

signals:
    //! The user requested to delete this archive.
    void requestDelete();
    //! The user requested more information about this archive.
    void requestInspect();
    //! The user requested to restore this archive.
    void requestRestore();
    //! The user requested to see the Job which created this archive.
    void requestGoToJob();
    //! Remove this item from the Archive list.
    void removeItem();

protected:
    //! Processes requests to switch language.
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void update();

private:
    Ui::ArchiveListWidgetItem _ui;
    QWidget    *_widget;
    ArchivePtr _archive;

    void setArchive(ArchivePtr archive);
    void updateUi();
};

#endif // ARCHIVELISTWIDGETITEM_H
