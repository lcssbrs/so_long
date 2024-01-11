# Projet So_Long - Ecole 42

## Description
Bienvenue dans So_Long, un projet réalisé dans le cadre du cursus de l'école 42. L'objectif de ce projet est de créer un jeu simple en utilisant la bibliothèque graphique MinilibX.

## Prérequis
Assurez-vous d'avoir MinilibX installé sur votre système.

## Installation
1. Clonez ce dépôt sur votre machine locale.
   ```bash
   git clone https://github.com/votre-utilisateur/so_long.git
   cd so_long
2. Compilez le projet en exécutant la commande make.
   ```bash
Copy code
make


## Utilisation
Une fois le projet compilé, lancez le jeu avec la commande suivante :

bash
Copy code
./so_long maps/map_test.ber


## Règles du jeu
Votre objectif est de déplacer votre personnage ('P') à travers la carte tout en collectant les collectibles ('C').
Évitez les ennemis ('E') qui se déplacent aléatoirement.
La sortie ('E') vous permet de quitter le niveau et de passer au suivant.
Assurez-vous de collecter tous les collectibles avant de quitter pour compléter le niveau.


## Fonctionnalités
Gestion des événements clavier pour déplacer le personnage.
Affichage de la carte et des objets en utilisant la bibliothèque MinilibX.
Gestion des collisions, des collectibles et de la sortie.
Auteurs
Lucas Seiberras
