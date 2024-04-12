#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FenetrePrincipale;
}
QT_END_NAMESPACE

class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    //** Constructeur et destructeur **//
    FenetrePrincipale(QWidget *parent = nullptr);
    ~FenetrePrincipale();

    void paintEvent(QPaintEvent *event) override;

private slots:
    //** Methodes **//
    int on_ImportImageButton_clicked();

    int on_ExportImageButton_clicked();

    void on_positionHautPushButton_clicked();

    void on_positionDroitePushButton_clicked();

    void on_positionBasPushButton_clicked();

    void on_positionGauchePushButton_clicked();

    void on_hauteurPlusPushButton_clicked();

    void on_hauteurMoinsPushButton_clicked();

    void on_largeurPlusPushButton_clicked();

    void on_largeurMoinsPushButton_clicked();

private:
    Ui::FenetrePrincipale *ui;

    QString CheminImage;
};

#endif // FENETREPRINCIPALE_H
