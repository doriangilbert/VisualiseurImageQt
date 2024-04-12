#include "FenetrePrincipale.h"
#include "ui_FenetrePrincipale.h"
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPainter>

FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FenetrePrincipale)
{
    ui->setupUi(this);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete ui;
}

void FenetrePrincipale::paintEvent(QPaintEvent *event)
{
    // Appel à la méthode de la classe parente
    QWidget::paintEvent(event);

    if (CheminImage.isEmpty())
    {
        return;
    }

    QImage Image(CheminImage);

    if (!Image.load(CheminImage))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Erreur lors du chargement de l'image!");
        messageBox.setFixedSize(500,200);
        return;
    }

    // Redimensionner l'image si elle dépasse la taille maximale
    QImage scaledImage = Image.scaled(850, 550, Qt::KeepAspectRatio);

    // Utiliser QPainter pour dessiner l'image sur le widget
    QPainter Painter(this);
    Painter.drawImage(0, 0, scaledImage);

    // Dessiner un rectangle autour de l'image
    Painter.setPen(Qt::red); // Définir la couleur du trait
    Painter.drawRect(0, 0, scaledImage.width(), scaledImage.height()); // Dessiner le rectangle autour de l'image
}

int FenetrePrincipale::on_ImportImageButton_clicked()
{
    // On ouvre la boîte de dialogue pour choisir un fichier .SQLite
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choix de l'image à importer"), "", tr("Fichiers png (*.png)"));

    // Si aucun fichier n'a été choisi, on envoie un message d'erreur
    if (fileName.isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Vous n'avez pas choisi de fichier!");
        messageBox.setFixedSize(500,200);
        return 0;
    }

    // Si un fichier a été choisi
    else
    {
        CheminImage = fileName;
        update();

    }
    return 1;
}

int FenetrePrincipale::on_ExportImageButton_clicked()
{
    /*// On ouvre la boîte de dialogue pour choisir un fichier .SQLite
    //QString fileName = QFileDialog::getOpenFileName(this, tr("Choix du fichier à exporter"), "", tr("Fichiers png (*.png)"));

    // Si aucun fichier n'a été choisi, on envoie un message d'erreur
    //if (fileName.isEmpty())
    {

    }

    // Si un fichier a été choisi
    else
    {

    }*/
}

void FenetrePrincipale::on_positionHautPushButton_clicked()
{

}


void FenetrePrincipale::on_positionDroitePushButton_clicked()
{

}


void FenetrePrincipale::on_positionBasPushButton_clicked()
{

}


void FenetrePrincipale::on_positionGauchePushButton_clicked()
{

}


void FenetrePrincipale::on_hauteurPlusPushButton_clicked()
{

}


void FenetrePrincipale::on_hauteurMoinsPushButton_clicked()
{

}


void FenetrePrincipale::on_largeurPlusPushButton_clicked()
{

}


void FenetrePrincipale::on_largeurMoinsPushButton_clicked()
{

}

