#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define finca '\0'

int prioridad(char simbol); // Primera funcion, para saber la prioridad 
void expreposfija(char infi[], int longitud, int pili[], char exprepos[]); //Funci�n para convertir la expresi�n infija a posfija
int valorar(char simp, char opera[]);//Funci�n para verificar d�nde est�n los operadores en la cadena
float resultado(char posf[], int longi); //Funci�n para resolver la  funci�n estando en posfija


int main() {
	int tam; char infija[20];
	int pila[20]; char posfija[20];
	float r;
	
	printf("Ingresa la expresi�n simple:"); //Se ingresa la expresi�n aritm�tica
	gets(infija);
	
	tam = strlen(infija);  //Se busca la longitud de la expresi�n ingresada 
	
	expreposfija(infija, tam, pila, posfija); //Funci�n para convertir la expresi�n infija a posfija
	
	r=resultado(posfija,tam);   //Funci�n para resolver la expresi�n aritm�tica ingresada mediante la posfija
	
	printf("\n El resultado es: %.2f", r);
	
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
	printf("La longit es %i",longitud);
	printf("\n\n");
	
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
	
	
	printf("La expresi�n en notacion posfija es; \n");  //Impresi�n de la expresi�n posfija
	
		for(i=0; i<k; i++){
			printf("%c", exprepos[i]);
		}
		printf("\n\n");
	
	}

float resultado(char posf[],int longi){
	int i;int v; int k;
	char aux; char operadores[6] = {'+','-','/','*','(',')'};
	float pilaaux[20]; float result;
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

	
	
	
	

