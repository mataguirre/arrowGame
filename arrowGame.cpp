#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdlib>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int userIn;
int score = 0;
int win;
int loss;
char userIn1;

void menuList() {
	printf("--- Arrow Game ---");
	printf("\n\n1) Jugar");
	printf("\n2) Score");
	printf("\n3) Creditos");
	printf("\n4) Salir");
}

void subMenuList() {
	printf("\n--- Dificultad ---");
	printf("\n\na) Dificil");
	printf("\nb) Facil");
}

void menuInput() {
	menuList();
	printf("\n\nSeleccione una opcion: "); scanf("%i", &userIn);
	while(userIn < 1 or userIn > 4) {
		printf("Seleccione una opcion valida: "); scanf("%i", &userIn);	
	}
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
	for(int i = 1; i <= times; i++) {
		int human;
		int pc;
		int positions[] = {72, 80, 75, 77};
		int index;
		int loss;
		int win;
	
		win = 0;
		loss = 0;
		human = 0;
		index = 0;
		pc = 0;
		
		index = rand() % 4;
		pc = positions[index];
		
		printArrow(pc);
		
		getch();
		human = getch();
		
		if(human == pc) {
			win++;
		} else {
			loss++;
		}
	}	
	
	if(win > loss) {
		score += 100;
	} else {
		score -= 100;
	}
}

int main() {
	menuInput();
	
	while(userIn != 4) {
		
		if(userIn == 1) {
			subMenuInput();
			
			if(userIn1 == 'a') {
				printf("Opcion Dificil\n");
				arrowGame(50);
				
			} else if(userIn1 == 'b') {
				printf("Opcion Facil\n");
				arrowGame(10);
				
			} else {
				printf("\n");
				menuInput();
			}
		
		} else if(userIn == 2) {
			printf("\nLast score: %i points", score);
			printf("\n\n");
			menuInput();
			
		} else if(userIn == 3) {
			printf("\nGame developed by Aguirre Matias.\n\nThank you for playing <3");
			printf("\n\n");
			menuInput();
		} 
	}
}
