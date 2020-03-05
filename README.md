# push_swap

*Résumé: Ce projet vous demande de trier des données sur une pile,
avec un set d’instructions limité, en moins de coups possibles.
Pour le réussir, vous devrez manipuler différents algorithmes de tri
et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.*

## Introduction
Le projet Push_swap est un projet d’algo simple et efficace : il faut trier. Vous avez
à votre disposition un ensemble d’entiers, deux piles, et un ensemble d’instructions pour
manipuler les piles.

Votre but ? Ecrire deux programmes en C :

- Un premier nommé checker qui prend des entiers en paramètres et qui lit
des instructions sur l’entrée standard. Une fois ces instructions lues, checker les exécute
puis affiche OK si les entiers sont triés, ou KO sinon.
- Un second nommé push_swap qui calcule et affiche sur la sortie standard le plus
petit programme dans le langage des instructions de Push_swap qui trie les entiers
passés en paramètre.

## Règles du jeu
Le jeu est constitué de 2 piles nommées a et b.
- Au départ :
  * a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
  * b est vide
- Le but du jeu est de trier a dans l’ordre croissant.
- Pour ce faire, on ne dispose que des opérations suivantes :

   __sa__ : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
rien s’il n’y en a qu’un ou aucun.  
   __sb__ : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait
rien s’il n’y en a qu’un ou aucun.  
   __ss__ : sa et sb en même temps.  
   __pa__ : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
rien si b est vide.  
   __pb__ : push b - prend le premier élément au sommet de a et le met sur b. Ne fait
rien si a est vide.  
   __ra__ : rotate a - décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.  
   __rb__ : rotate b - décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.  
   __rr__ : ra et rb en même temps.  
   __rra__ : reverse rotate a - décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.  
   __rrb__ : reverse rotate b - décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.  
   __rrr__ : rra et rrb en même temps.  
   
## Le programme *checker*
Le programme *checker* prends en paramètre la pile sous la forme d'une liste d'entiers.
Le premier paramètre est au sommet de la pile (attention donc à l’ordre).
Checker doit ensuite attendre de lire des instructions sur l’entrée standard, chaque
instruction suivie par un ’\n’. Une fois toutes les instructions lues, le checker va
exécuter ces instructions sur la pile d’entiers passée en paramètres.
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>
```
## Le programme *push_swap*
Le programme *push_swap* prend en paramètre la
pile a sous la forme d’une liste d’entiers. Le premier paramètre est au sommet
de la pile (attention donc à l’ordre). Si aucun paramètre n’est passé, push_swap
termine immédiatement et n’affiche rien.  
Le programme doit afficher le programme composé de la plus petite suite d’instructions
possible qui permet de trier la pile a, le plus petit nombre étant au sommet.
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

## Téléchargement
```
git clone https://github.com/manki23/push_swap.git ; cd push_swap ; make
```
## Utilisation
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
9
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$>
```
## Options Bonus
```
Pour les deux programmes :
-c    affichage avec couleurs
-sN   choisir la valeur du sleep avec N entre 0 et 9

Uniquement avec le programme checker :
-v    option verbose, pour voir le détail des opérations
```
