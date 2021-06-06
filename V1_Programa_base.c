#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Para sleep
#include <math.h>
#define hori 110 //Horizontal
#define verti 15 //Vertical
#define PI 3.141592

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
		int op;
		float x,seno,coseno,tangente, rad; //Trigo
		int n; float y; double result; //Exponenciales, log, LN
		
		gotoYX(8,30);
		printf("Bienvenido, oprime enter para continuar");
		getchar();
		system("cls");
		
		DespEncabezado();
		gotoYX(4,4);
		printf("- Funciones trigonometricas - Opción 1");
		gotoYX(7,4);
		printf("- Exponencial, logaritmo, logaritmo natural - Opción 2");
		gotoYX(11,4);
		printf("- Ingreso de expresiones - Opción 3");
		gotoYX(13,4);
		printf("Ingresa la opcion:");
		scanf("%i",&op);
		
		switch (op) {
		case 1: //Funciones trigonometricas
			system("cls");
			DespEncabezado();
			gotoYX(4,4);
			printf("- Seno - Opción 1");
			gotoYX(7,4);
			printf("- Coseno - Opción 2");
			gotoYX(11,4);
			printf("- Tangente - Opción 3");
			gotoYX(13,4);
			printf("Ingresa la opcion:");
			scanf("%i",&op);
			if(op==1){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresa un angulo en grados:");
				scanf("%f",&x);
				rad=x*PI/180.0;
				seno= sin(rad);
				gotoYX(11,4);
				printf("Sen(%8.2f) = %8.2f",x,seno);
				printf("\n\n");
			}
			if(op==2){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresa un angulo en grados:");
				scanf("%f",&x);
				rad=x*PI/180.0;
				coseno= cos(rad);
				gotoYX(11,4);
				printf("cos(%8.2f) = %8.2f",x,coseno);
				printf("\n\n");
			}
			if(op==3){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresa un angulo en grados:");
				scanf("%f",&x);
				rad=x*PI/180.0;
				tangente= tan(rad);
				gotoYX(11,4);
				printf("tan(%8.2f) = %8.2f",x,tangente);
				printf("\n\n");
			}
			
			break;
			
		case 2: //Exponecial, logaritmo ...
			system("cls");
			DespEncabezado();
			gotoYX(4,4);
			printf("- Exponecial - Opción 1");
			gotoYX(7,4);
			printf("- Logaritmo natural - Opción 2");
			gotoYX(11,4);
			printf("- Logaritmo base 10 - Opción 3");
			gotoYX(13,4);
			printf("Ingresa la opcion:");
			scanf("%i",&op);
			if(op==1){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresar la potencia del expoencial e^n:");
				scanf("%i", &n);
				gotoYX(11,4);
				printf(" e^%i = %8.2f", n,exp(n));
			}
			if(op==2){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresar y de Ln(y):");
				scanf("%f", &y);
				result = log(y);
				gotoYX(11,4);
				printf("Ln (%8.2f) = %8.2lf",y,result);
			}
			
			if(op==3){
				system("cls");
				DespEncabezado();
				gotoYX(7,4);
				printf("Ingresar y de  Log(y):");
				scanf("%f", &y);
				result = log10(y);
				gotoYX(11,4);
				printf("Log (%8.2f) = %8.2lf",y,result);
			}
			break;
			
		case 3: // Inrego de expresiones
			system("cls");
			DespEncabezado();
			gotoYX(7,4);
			printf("Estamos trabajando en ello");
			break;
		}
		
		printf("\n\n\n");
		
		
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
