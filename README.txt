PROJET D'ALGORITHMIQUE ET PROGRAMMATION PROCEDURALE

Développé par Romain Pignol, Théophile Berthier, Hassan El Kabbaj.

Commande de compilation : gcc 2048.c -o 2048 $(sdl2-config --cflags --libs)		SOUS LINUX
			   gcc src/2048.c -o bin/2048 -I include -L lib -lmingw32 -lSDL2 	SOUS WINDOWS
			   
Commande d'exécution : ./2048									SOUS LINUX
			/bin/2048 ou /bin/2048.exe						SOUS WINDOWS

Explication des carrés de couleurs 
- Jaune représente le carré 2
- Vert clair représente le carré 4
- Vert foncé représente le carré 8
- Bleu clair représente le carré 16
- Bleu foncé représente le carré 32
- Violet représente le carré 64
- Rose représente le carré 128
- Rouge représente le carré 256
- Orange représente le carré 512
- Gris représente le carré 1024
- 2048 est représenté en Noir pour le skin 1 et en Blanc pour le skin 2
