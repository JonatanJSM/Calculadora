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
	
	
	
	expreposfija(infija, tam, pila, posfija);
	
}

int valorar(char simp, char opera[]){
	int v = 2; int j;
	for(j=0;j<6;j++){
		if(simp == opera[j]){
			v = 1;
		}
	}
	return v;
}
	
	
	
	int prioridad(char simbol){  //Primera función, para saber la prioridad
		int pri = 0;
		
		if(simbol =='(' || ')'){            //Modificar estoooooooooooooooo
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
					if(auxsimbo == '('){   
						pili[j] = auxsimbo;
						j++;
					}
					
					else if(auxsimbo ==')'){
						while(pili[j] != '('){  //esto vacía la cadena
							exprepos[k] = pili[j];
							k++;
							j--;
						}
						j--; //Para dejar a la j en 0, y así llenar desde 0 la pila
						
					}
					
					//a+(c+b)
					//*
					else {
						priori = prioridad(auxsimbo);
						
						if (priori <= prioridad(pili[j])){
							priori = prioridad(auxsimbo);   
                            //j=1
							
							while ((j>0) && (priori <= prioridad(pili[j]))){
								exprepos[k] = pili[j];
								k++;
								j--;
								printf("j=%i",j);
								//printf("while(%i, %c)", j,pili[j]);
							}
							
							j++;
							pili[j] = auxsimbo;
							//printf("fuerawhile(%i, %c)", j,pili[j]);
							//printf("\n\n");
						}
						else {
							pili[j] = auxsimbo;
							j++; //aquí 
						}
						
					}
				}
				
				else{ //Aquí entra si es numero o variable
					exprepos[k] = auxsimbo;
					k++;
				}
				
			}
			
			//Cuando termina el ciclo for, puede que quede algo en la pila
			// Y con esto lo sacamos
			while(j>=0){
				exprepos[k] = pili[j];
				k++;
				j--;
			}
			exprepos[k-1]=finca; //Modificar estoooooooooooooooo(LISTO)
			
			
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
