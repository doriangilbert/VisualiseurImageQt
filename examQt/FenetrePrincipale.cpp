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
    QImage scaledImage = Image.scaled(850, 480, Qt::KeepAspectRatio);

    // On stocke la taille de l'image
    HautImage = 0;
    BasImage = scaledImage.height();
    GaucheImage = 0;
    DroiteImage = scaledImage.width();

    // Utiliser QPainter pour dessiner l'image sur le widget
    QPainter Painter(this);
    Painter.drawImage(0, 0, scaledImage);

    // Dessiner un rectangle autour de l'image
    Painter.setPen(Qt::red); // Définir la couleur du trait

    // Premier import de l'image
    if (Hauteur == 0 && Largeur == 0)
    {
        // On stocke la taille du rectangle que l'on va changer par la suite.
        Hauteur = scaledImage.height();
        Largeur = scaledImage.width();
        PositionX = 0;
        PositionY = 0;
    }

    // On dessine le rectangle.
    Painter.drawRect(PositionX, PositionY, Largeur, Hauteur); // Dessiner le rectangle autour de l'image
}

void FenetrePrincipale::on_ImportImageButton_clicked()
{
    // On ouvre la boîte de dialogue pour choisir un fichier .png.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choix de l'image à importer"), "", tr("Fichiers png (*.png)"));

    // Si aucun fichier n'a été choisi, on envoie un message d'erreur.
    if (fileName.isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Vous n'avez pas choisi de fichier!");
        messageBox.setFixedSize(500,200);
        return;
    }

    // Si un fichier a été choisi.
    else
    {
        CheminImage = fileName;
        Hauteur = 0;
        Largeur = 0;
        update();
    }
    return;
}

void FenetrePrincipale::on_ExportImageButton_clicked()
{
    // On ouvre la boîte de dialogue pour choisir un répertoire pour stocker l'image.
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Choisir un dossier"), "", QFileDialog::ShowDirsOnly);

    // Si aucun répertoire n'a été choisi, on envoie un message d'erreur.
    if (folderPath.isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Vous n'avez pas choisi de répertoire!");
        messageBox.setFixedSize(500,200);
        return;
    }

    // Si un répertoire a été choisi
    else
    {

    }
    return;
}

void FenetrePrincipale::on_positionHautPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionY > ui->pasVariationSpinBox->value())
    {
        // Déplacement du rectangle vers le haut selon le pas de variation
        PositionY -= ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_positionDroitePushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionX + Largeur + ui->pasVariationSpinBox->value() < DroiteImage)
    {
        // Déplacement du rectangle vers la droite selon le pas de variation
        PositionX += ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_positionBasPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionY + Hauteur + ui->pasVariationSpinBox->value() - 1 < BasImage)
    {
        // Déplacement du rectangle vers le bas selon le pas de variation
        PositionY += ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_positionGauchePushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionX > ui->pasVariationSpinBox->value() - 1)
    {
        // Déplacement du rectangle vers la gauche selon le pas de variation
        PositionX -= ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_hauteurPlusPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionY + Hauteur + ui->pasVariationSpinBox->value() - 1 < BasImage)
    {
        // Augmentation de la hauteur du rectangle selon le pas de variation
        Hauteur += ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_hauteurMoinsPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (Hauteur > ui->pasVariationSpinBox->value() + 1)
    {
        // Diminution de la hauteur du rectangle selon le pas de variation
        Hauteur -= ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_largeurPlusPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (PositionX + Largeur + ui->pasVariationSpinBox->value() - 1 < DroiteImage)
    {
        // Augmentation de la largeur du rectangle selon le pas de variation
        Largeur += ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}


void FenetrePrincipale::on_largeurMoinsPushButton_clicked()
{
    // Si le rectangle ne dépasse pas la zone de l'image
    if (Largeur > ui->pasVariationSpinBox->value() + 1)
    {
        // Diminution de la largeur du rectangle selon le pas de variation
        Largeur -= ui->pasVariationSpinBox->value();
    }
    // Mise à jour de l'interface
    update();
}

