#include<iostream>
#include<conio.h>
#include<string.h>
#include <unistd.h>
#include <cstdlib>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int userIn;
char userIn1;
float winPercent;
int win;
int cont;
int cont1;

void intro() {
	printf("Readme");
	printf("\n\nEste juego fue desarrollado por NZS Software Develop\nante cualquier problema contactarse de forma directa\ncon la empresa para solucionarlo.\n\n");
}

void menuList() {
	printf("--- Arrow Game ---");
	printf("\n\n1) Jugar");
	printf("\n2) Score");
	printf("\n3) Creditos");
	printf("\n4) Salir");
}

void subMenuList() {
	printf("--- Dificultad ---");
	printf("\n\na) Dificil");
	printf("\nb) Facil");
	printf("\nc) Volver al menu principal");
}

void menuInput() {
	menuList();
	printf("\n\nSeleccione una opcion: "); scanf("%i", &userIn);
}

void subMenuInput() {
	subMenuList();
	printf("\n\nSeleccione una opcion: "); scanf("%s", &userIn1);
}

void printArrow(int arrow) {
	switch(arrow) {
		case KEY_UP: // Número del teclado 72
			printf("\t ------------ \n");
			printf("\t\t^ \n");
			printf("\t\t| \n");
			printf("\t ------------ \n");
			break;		
		case KEY_DOWN: // Número del teclado 80
			printf("\t ------------ \n");
			printf("\t\t| \n");
			printf("\t\tv \n");
			printf("\t ------------ \n");
			break;		
		case KEY_LEFT: // Número del teclado 75
			printf("\t ------------ \n");
			printf("\t\t<= \n");
			printf("\t ------------ \n");
			break;	
		case KEY_RIGHT: // Número del teclado 77
			printf("\t ------------ \n");
			printf("\t\t=> \n");
			printf("\t ------------ \n");
			break;	
		default:
			break;
	}
}

void arrowGame(int times) {
	int human;
	int pc;
	int positions[] = {72, 80, 75, 77};
	int index;
	int contT;

	human = 0;
	index = 0;
	pc = 0;
	contT = 0;
	win = 0;
	
	for(int i = 1; i <= times; i++) {
		contT++;
				
		index = rand() % 4;
		pc = positions[index];
		
		printArrow(pc);
		
		getch();
		human = getch();
		
		if(human == pc) {
			printf("\nACERTASTE! +1 points\n\n");
			win++;
		} else {
			printf("\nNO ACERTASTE! +0 points\n\n");
		}
	}
	
	winPercent = (win * 100) / contT;
	
	printf("Porcentaje de victorias: %.2f%\n", winPercent);
}

int main() {	
	intro();
	menuInput();
	
	while(userIn != 4) {
		
		if(userIn == 1) {
			
			printf("\n");
			subMenuInput();
			
			if(userIn1 == 'a') {
				printf("\n\nEl juego comienza en:\n\n");
				cont = 5;
				while(cont > 0) {
					sleep(1);
					printf("%i ", cont);
					cont--;
				}
				sleep(1);
				printf("\n\nYA!\n\n");
				sleep(1);
				arrowGame(50);
								
			} else if(userIn1 == 'b') {
				printf("\nEl juego comienza en:\n\n");
				cont1 = 5;
				while(cont1 > 0) {
					sleep(1);
					printf("%i ", cont1);
					cont1--;
				}
				sleep(1);
				printf("\n\nYA!\n\n");
				sleep(1);
				arrowGame(10);
				
			} else {
				printf("\n");
				menuInput();
			}
		
		} else if(userIn == 2) {
			printf("\nLast score: %i points", win);
			printf("\n\n");
			menuInput();
			
		} else if(userIn == 3) {
			printf("\nGame developed by Aguirre Matias.\nThank you for playing <3");
			printf("\n\n");
			menuInput();
		} 
	}
}
