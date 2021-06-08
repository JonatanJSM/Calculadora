#include <stdio.h>
#include <string.h>
#define finca '\0'

int prioridad(char simbol); // Primera funcion, para saber la prioridad 


// infi = infija[20]     lonfitud es para el tamaño     pili = pila[]    exprepos[]= posfija[20]   
void expreposfija(char infi[], int longitud, int pili[], int exprepos[]); //Función para pasar a posfijo

int valorar(char simp, char opera[]);

int main(int argc, char *argv[]) {
	int tam; char infija[20];
	int pila[20]; int posfija[20];
	
	
	printf("Ingresa la expresión simple:"); //Se ingresa la cadena
	gets(infija);
	
	tam = strlen(infija);  
	//printf("\n\n Tamaño %i", tam) // Para comprobar la longitud de la cadena
	
	
	expreposfija(infija, tam, pila, posfija);
	
}

int valorar(char simp, char opera[]){
	int v = 2; int j;
	for(j=0;j<6;j++){
		//printf("(%c=)",opera[j]);
		if(simp == opera[j]){
			v = 1;
		}
	}
	return v;
}



int prioridad(char simbol){  //Primera función, para saber la prioridad
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
	
	
	// infi = infija[20]     lonfitud es para el tamaño     pili = pila[]    exprepos[]= posfija[20] 
	void expreposfija(char infi[], int longitud, int pili[], int exprepos[]){  //Funcion para pasar a posfijo
		char operadores[6] = {'+','-','/','*','(',')'};
		char auxsimbo; // Se puede cambiar luego por la cadena
		int priori;
		int i,j,k,v; //La j lo utilizo para la pila "Tener en cuenta en donde utilizarlo, no es lo mismo que i"
		printf("La longit es %i",longitud);
		printf("\n\n");
		
		j=0; k=0;
		
		for(i=0; i<longitud; i++){
			auxsimbo = infi[i];
			v = valorar(auxsimbo,operadores);
			
			/*
			printf("(%i)",v); //Prueba
			printf("{%c}",auxsimbo); //Prueba
			printf("\n");//Prueba
			*/
			
			if(v == 1){
				//printf("(Ciclo %c)",auxsimbo);  aquí compruebo si entra el operador
				
				if(auxsimbo == '('){   //
					pili[j] = auxsimbo;
					j++;
					//printf("(1Ciclo %c)",auxsimbo); prueba
				}
				
				else if(auxsimbo ==')'){
					//printf("(2Ciclo %c)",auxsimbo); Prueba
					printf("(1 %c)\n",exprepos[k]);
					printf("(1 %c)\n",pili[j]);
					while(pili[j] != '('){  //esto vacía la cadena
						printf("(2 %c)\n",exprepos[k]);
						printf("(2 %c)\n",pili[j]);
						exprepos[k] = pili[j];
						k++;
						j--;
					}
					j--; //Para dejar a la j en 0, y así llenar desde 0 la pila
					
				}
				
				else{
					//printf("(3Ciclo %c)",auxsimbo); Prueba
					priori = prioridad(auxsimbo);
					//printf("priori %i\n", priori); Prueb
					printf("(j %i)\n",j);
					while(j>0 && (priori <= prioridad(pili[j]))){
						printf("(2j %i)\n",j);
						printf("La prioridad es %i",prioridad(pili[j]));
						exprepos[k] = pili[j];
						k++;
						j--; // Si se quita de la pila lo tenemos que reducir
					}
					j++;
					pili[j] = auxsimbo;
					// printf("(1Pila %c )\n",pili[j]);
				}
			}
			
			else{ //Aquí entra si es numero o variable
				exprepos[k] = auxsimbo;
				k++;
			}
			
		}
		
		//Cuando termina el ciclo for, puede que quede algo en la pila
		// Y con esto lo sacamos
		printf("k1=%i\n",k);
		//printf("j1=%i\n",j);
		while(j>=0){
			//printf("j2=%i",j);
			exprepos[k] = pili[j];
			k++;
			j--;
		}
		//printf("k2=%i\n",k);
		//printf("Ultimo %c \n",exprepos[k]);
		exprepos[k-1]=finca;
		
		
		printf("La expresión en notacion posfija es; \n");
		for(i=0; i<k; i++){
			printf("%c", exprepos[i]);
		}
		printf("\n\n");
		for(i=0; i<k; i++){
			printf("%i =", exprepos[i]);
		}
		
		printf("\n\n");
		i=0;
		while(exprepos[i] != finca){
			printf("%c", exprepos[i]);
			i++;
		}
	}
