PROJET D'ALGORITHMIQUE ET PROGRAMMATION PROCEDURALE

Développé par Théophile Berthier, Hassan El Kabbaj, Romain Pignol.

Commande de compilation : gcc 2048.c -o 2048 $(sdl2-config --cflags --libs)		SOUS LINUX
			   gcc src/2048.c -o bin/2048 -I include -L lib -lmingw32 -lSDL2 	SOUS WINDOWS
			   
Commande d'exécution : ./2048									SOUS LINUX
			/bin/2048 ou /bin/2048.exe						SOUS WINDOWS

Explication des carrés de couleurs 
- Jaune représente le carré 2
- Vert représente le carré 4
- Bleu 1 représente le carré 8
- Bleu 2 représente le carré 16
- Bleu 3 représente le carré 32
- Rouge 1 représente le carré 