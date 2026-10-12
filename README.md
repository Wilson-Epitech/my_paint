<div align="center">

# My Paint

**Un petit Paint écrit en C.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="CSFML" src="https://img.shields.io/badge/CSFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/>

<sub>Projet à 2 · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/my_paint.gif" alt="My Paint" width="820"/></p>

## En deux mots

Un logiciel de dessin en C avec la CSFML : crayon, gomme, formes et couleurs, avec une vraie barre d'outils et des menus.

## Ce que ça fait

- Crayon et gomme, avec une taille réglable
- Forme du pinceau : carré ou rond
- Palette de couleurs et sélecteur
- Barre de menus avec menus déroulants (fichier, aide)
- Ouverture et sauvegarde d'images

## Sous le capot

Le dessin se fait dans une image CSFML mise à jour pixel par pixel sous le curseur, avec la forme et la taille du pinceau. La barre d'outils est faite de boutons génériques qui ont leur propre état (survol, actif).

## Lancer le projet

```bash
make
./my_paint
```

## L'équipe

<a href="https://github.com/Wilson-Epitech/my_paint/graphs/contributors"><img src="https://contrib.rocks/image?repo=Wilson-Epitech/my_paint" alt="Contributeurs"/></a>

Mathis Brehm, Wilson Bordichon

**Ma part :** J'ai fait la **sélection des outils** (forme, taille et couleur du pinceau), le dessin des formes, les boutons génériques et le redimensionnement automatique de la fenêtre.
