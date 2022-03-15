
INFORMATION MAKEFILE: Nous avons modifié le Makefile de sorte à simplifier les différents tests pour les différents exos.
Pour tester les exercices 1 et 2 (pile et file) en même temps, il faut faire "make test" puis "./xmlTest". Cela exécute "main_test.c".
Pour tester les exercices 3, 4, 5 en même temps, il faut faire "make" puis "./xmlChecker". Cela exécute "main.c".
Vous pouvez toujours changez les fonctions testées directement dans les différents mains si vous le souhaitez.


EXERCICE 1:
Tout marche normalement.

EXERCICE 2:
Tout marche normalement.
La seule différence est que l'on affiche dans le sens inverse la file (la tête en bas et la queue en haut) mais cela ne pose pas réellement de problème.

EXERCICE 3:
Tout marche normalement.
Question 3: La fonction "fonctionXML" permet d'afficher toutes les balises du fichiers avec tabulations, et ne montre pas ce qu'il se situe entre les différentes balises.

EXERCICE 4:
Tout marche normalement.

EXERCICE 5:
Tout marche jusqu’à un certain point. En effet, cela nous affiche dans l'ordre les expériences comme on le veut mais à partir de l’expérience "New Test Projet Star" nous avons segfault que l'on arrive pas à régler. Il y'a peut être un problème dans le fichier que l'on nous a mis à disposition ou alors un problème plus profond venant de notre code que nous n'arrivons pas à déceler malheureusement.
