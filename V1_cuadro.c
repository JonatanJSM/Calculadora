#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#define NMAX 11
 //  (4+5*5)+2(3+4)/30
int gotoYX(int columna, int linea){
	COORD coord;
	coord.Y= columna;
	coord.X=linea;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	return 0;
}
	
	void DespEncabezado();
	
	
	//principal
	int main(int argc, char *argv[]) {

	DespEncabezado();
	
	Sleep(250);
		return 0;
	}
	
	
	void DespEncabezado(){
		int i,j;
		system("cls");
		
		for(i=2; i<30; i++){
			for(j=2; j<60; j++){
				if(i == 2 || i == 30-1
				   ){
					gotoYX(i,j);
					printf("%c", 177);
				}
				else if(j == 2 || j == 60-1){
					gotoYX(i,j);
					printf("%c", 177);
				}
				else{
					gotoYX(i,j);
					printf(" ");
				}
			}
			printf("\n");
		}
		Sleep(250);
	}
		
