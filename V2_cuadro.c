#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Para sleep
#include <math.h>
#define hori 110 //Horizontal
#define verti 15 //Vertical

int gotoYX(int columna, int linea){
	COORD coord;
	coord.Y= columna;
	coord.X=linea;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	return 0;
}
	
	void DespEncabezado();
	
	
	//Parte principal en donde se llaman las funciones
	int main(int argc, char *argv[]) {
		
	printf("Calculadora Casio classwis");
	DespEncabezado();
	
		return 0;
	}
	
	
	void DespEncabezado(){
		int i,j;  //Para borrar, si notas, antes del cuadro hay un espacio
		//system("cls");
		
		for(i=2; i<verti; i++){
			for(j=2; j<hori; j++){
				// Comienzan en i=2 y j=2 pero puede ser 1
				//Es necesario el verti - 1 para que quede bien  
				if(i == 2 || i == verti-1
				   ){
					gotoYX(i,j);
					printf("%c", 177);
				}                      //Es necesario hori -1 o no quedaría bien
				else if(j == 2 || j == hori-1){
					gotoYX(i,j);
					printf("%c", 177); // Los 177s son el caracter que se imprime
				}
				else{
					gotoYX(i,j);
					printf(" ");
				}
			}
			printf("\n");
		}
		Sleep(250); //Para que se imprima lento el cuadro, si lo quitas es más rapido
	}
		
