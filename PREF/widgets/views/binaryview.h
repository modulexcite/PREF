#ifndef BINARYVIEW_H
#define BINARYVIEW_H

#include <QFile>
#include "abstractview.h"
#include "platform/loadeddata.h"
#include "../../models/datainspectormodel.h"
#include "../../models/templatemodel.h"

namespace Ui {
class BinaryView;
}

class BinaryView : public AbstractView
{
    Q_OBJECT

    public:
        explicit BinaryView(QHexDocument *document, QLabel* lblstatus, const QString& loadedfile, QWidget *parent = 0);
        virtual void updateToolBar(QToolBar *toolbar) const;
        ~BinaryView();

    private:
        void initSaveMenu();
        void analyze();
        void saveTo(QFile* f);

    private slots:
        void updateStatus() const;
        void loadTemplate();
        void save();
        void saveAs();
        void on_tvTemplate_clicked(const QModelIndex &index);

    private:
        Ui::BinaryView *ui;
        LoadedData* _loadeddata;
        DataInspectorModel* _datainspectormodel;
        TemplateModel* _templatemodel;
        QMenu* _savemenu;
};

#endif // BINARYVIEW_H
