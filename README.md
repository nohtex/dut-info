##TPs du DUT Informatique à l'université de Valenciennes (situé à Maubeuge)

###Pour les TPs de Bash et Base de données
Seuls les fichiers de rendu sont présents sur ce repo avec des screens des programmes effectués.

###Pour les programmes en C
**Premièrement, si vous utilisez Eclipse pour faire du C allez bien vous faire foutre.**

Pour compiler avec gcc en ligne de commande faites :
gcc -Wall -Wextra -Werror tpX.c ioap123.c

Pour lancer le programme compilé :
./a.out

Vous pouvez aussi donner un nom au programme compilé en compilant avec la commande suivante :
gcc -Wall -Werror -Wextra -o NomQuiDechire tpX.c ioap.c

Et ainsi pouvoir faire ça pour lancer le programme:
./NomQuiDechire

ioap123.c ioap123.h et tpX.c doivent être dans le même dossier

Les flags -Wall -Wextra et -Werror sont optionnels mais permettent de traiter les warning comme des erreurs vous obligeant ainsi à coder le plus proprement possible !
