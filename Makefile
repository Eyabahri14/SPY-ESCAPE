# -*- Makefile -*-

prog: main.o fonction.o map.o input.o enigme.o perso.o scrolling.o jeu.o minimap.o roto.o
	gcc main.o fonction.o map.o input.o enigme.o perso.o scrolling.o minimap.o jeu.o roto.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx -o prog -g

main.o: main.c
	gcc main.c -c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

jeu.o: jeu.c
	gcc jeu.c -c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

map.o: map.c map.h
	gcc -c map.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

input.o: input.c input.h
	gcc -c input.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

enigme.o: enigme.c enigme.h
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

perso.o: perso.c perso.h
	gcc -c perso.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

scrolling.o: scrolling.c scrolling.h
	gcc -c scrolling.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

minimap.o: minimap.c minimap.h
	gcc -c minimap.c -lSDL -lSDL_image -g

roto.o: roto.c roto.h
	gcc -c roto.c -lSDL -lSDL_image -lSDL_gfx -g

clean:
	rm *.o prog -f
