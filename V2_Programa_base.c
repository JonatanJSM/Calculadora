#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Para sleep
#include <math.h>
#define hori 110 //Horizontal
#define verti 15 //Vertical
#define PI 3.141592
#define finca '\0'


int prioridad(char simbol); // Primera funcion, para saber la prioridad 
void expreposfija(char infi[], int longitud, int pili[], char exprepos[]); //Funci�n para convertir la expresi�n infija a posfija
int valorar(char simp, char opera[]);//Funci�n para verificar d�nde est�n los operadores en la cadena
float resultado(char posf[], int longi); //Funci�n para resolver la  funci�n estando en posfija

int gotoYX(int columna, int linea){
	COORD coord;
	coord.Y= columna;
	coord.X=linea;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	return 0;
}
	
void DespEncabezado();

	
	//Parte principal en donde se llaman las funciones
int main() {
	int op;
	float x; float seno; float coseno; float tangente; float rad; //Trigo
	int n; float y; double result; //Exponenciales, log, LN
	int tam; char infija[30];
	int pila[30]; char posfija[30];
	float r;
	
	gotoYX(8,30);
	printf("Bienvenido, oprime enter para continuar");
	getchar();
	system("cls");
	
	DespEncabezado();
	gotoYX(4,4);
	printf("- Funciones trigonometricas - Opci�n 1");
	gotoYX(7,4);
	printf("- Exponencial, logaritmo, logaritmo natural - Opci�n 2");
	gotoYX(11,4);
	printf("- Ingreso de expresiones simples - Opci�n 3");
	gotoYX(13,4);
	printf("Ingresa la opcion:");
	scanf("%i",&op);
		
		switch (op) {
		case 1: //Funciones trigonometricas
			system("cls");
			DespEncabezado();
			gotoYX(4,4);
			printf("- Seno - Opci�n 1");
			gotoYX(7,4);
			printf("- Coseno - Opci�n 2");
			gotoYX(11,4);
			printf("- Tangente - Opci�n 3");
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
				gotoYX(12,4);
				getchar();
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
			printf("- Exponecial - Opci�n 1");
			gotoYX(7,4);
			printf("- Logaritmo natural - Opci�n 2");
			gotoYX(11,4);
			printf("- Logaritmo base 10 - Opci�n 3");
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
			printf("Ingresa la expresi�n simple:"); //Se ingresa la expresi�n aritm�tica
			scanf("%s",infija);
			
			tam = strlen(infija);  //Se busca la longitud de la expresi�n ingresada 
			
			expreposfija(infija, tam, pila, posfija); //Funci�n para convertir la expresi�n infija a posfija
			
			r = resultado(posfija,tam);   //Funci�n para resolver la expresi�n aritm�tica ingresada mediante la posfija
			
			gotoYX(11,4);
			printf("El resultado es: %8.2f", r);
			
			printf("\n\n");
			break;
		}
		
		
		return 0;
	}
	
	
void DespEncabezado(){
	int i,j;  //Para borrar, si notas, antes del cuadro hay un espacio
	//system("cls");
		
	for(i=2; i<verti; i++){
		for(j=2; j<hori; j++){
			// Comienzan en i=2 y j=2 pero puede ser 1
			//Es necesario el verti - 1 para que quede bien  
			if(i == 2 || i == verti-1){
				gotoYX(i,j);
				printf("%c", 177);
			}                      //Es necesario hori -1 o no quedar�a bien
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
		Sleep(150); //Para que se imprima lento el cuadro, si lo quitas es m�s rapido
}
	
	
	

int valorar(char simp, char opera[]){  //Funci�n para encontrar los operadores en la cadena
	int v = 2; int j;
	for(j=0;j<6;j++){
		if(simp == opera[j]){
			v = 1;
		}
	}
	return v;
}

int prioridad(char simbol){  //Funci�n para saber la prioridad de los operadores
	int pri = 0;

	if(simbol =='(' || ')'){            
		pri = 0;
	}
	
	if(simbol =='+' || simbol =='-'){
		pri = 1;
	}

	if(simbol =='*' || simbol =='/'){
		pri = 2;
	}
	
	return pri;
}
	
	
void expreposfija(char infi[], int longitud, int pili[], char exprepos[]){  //Funci�n para pasar a posfijo
		char operadores[6] = {'+','-','/','*','(',')'};
		char auxsimbo; 
		int priori;
		int i,j,k,v; 
		
		
		j=0; k=0;
		
		for(i=0; i<longitud; i++){
			auxsimbo = infi[i];
			v = valorar(auxsimbo,operadores);
			
			if(v == 1){
				if(auxsimbo == '('){   
					pili[j] = auxsimbo;
					j++;
				}
				
				else if(auxsimbo ==')'){
					while(pili[j-1] != '('){  //Ciclo para vaciar la cadena
						exprepos[k] = pili[j-1];
						k++;
						j--;
					}
					j--; //Para dejar a la j en 0, y as� llenar la pila desde 0				
				}
				
				else {
					priori = prioridad(auxsimbo);
					if (priori <= prioridad(pili[j-1])){
						priori = prioridad(auxsimbo);
						while ((j>0) && (priori <= prioridad(pili[j-1]))){
							exprepos[k] = pili[j-1];
							k++;
							j--; //
						}
						pili[j] = auxsimbo;
						j++;
					}
					else {
						pili[j] = auxsimbo;
						j++;
					}
				}
			}
			
			else{                      //En caso de que sea un operando entra en este ciclo
				exprepos[k] = auxsimbo;
				k++;
			}
			
		}
		
		//Cuando termina el ciclo for, puede que quede algo en la pila, en el caso de ser as�, lo sacamos con este ciclo
		while(j>=0){
			exprepos[k] = pili[j-1];
			k++;
			j--;
		}
		exprepos[k-1]=finca; 
		
		//printf("La expresi�n en notacion posfija es; \n");  //Impresi�n de la expresi�n posfija
		
		/*
		for(i=0; i<k; i++){
			printf("%c", exprepos[i]);
		}
		printf("\n\n");
		*/
		
}

		float resultado(char posf[],int longi){
			int i;int v; int k;
			char aux; char operadores[6] = {'+','-','/','*','(',')'};
			float pilaaux[30]; float result;
			char b[1];
			float baux; 
			
			k=0;
			
			for (i=0; i<longi; i++){
				aux = posf[i];
				v = valorar(aux,operadores);   //Verificar los operadores que se encuentran en la expresi�n posfija
				if(v==1){
					if (aux=='+') {         //Resolver la expresi�n dependiendo de los operadores que se encuentren
						result = (float)pilaaux[k-2] + (float)pilaaux[k-1];  //Se van sacando los valores guardados en la pila del �ltimo al primero ingresado
						pilaaux[k-2]= result;  //Se guarda el nuevo resultado en la pila 
						k--;
					}
					if (aux=='-') {
						result = (float)pilaaux[k-2] - (float)pilaaux[k-1];
						pilaaux[k-2]= result;
						k--;
					}
					
					if (aux=='*') {
						result = (float)pilaaux[k-2] * (float)pilaaux[k-1];
						pilaaux[k-2]= result;
						k--;
					}
					
					if (aux=='/') {
						result = (float)pilaaux[k-2] / (float)pilaaux[k-1];
						pilaaux[k-2]= result;
						k--;
					}
					
				}
				
				else{          //Pila para agrupar los n�meros 
					b[0] = aux;
					baux = atof(b);
					pilaaux[k] = baux;
					k++;
				}
				
			}
			
			result = pilaaux[0]; 
			
			return result; 
		}

	
