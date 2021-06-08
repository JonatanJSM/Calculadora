#include <stdio.h>
#include <string.h>
#define finca '\0'

int prioridad(char simbol); // Primera funcion, para saber la prioridad 


// infi = infija[20]     lonfitud es para el tamaño     pili = pila[]    exprepos[]= posfija[20]   
void expreposfija(char infi[], int longitud, int pili[], int exprepos[]); //Función para pasar a posfijo


int main(int argc, char *argv[]) {
	int tam; char infija[20];
	int pila[20]; int posfija[20];
	
	
	printf("Ingresa la expresión simple:"); //Se ingresa la cadena
	gets(infija);
	
	tam = strlen(infija);  
	//printf("\n\n Tamaño %i", tam) // Para comprobar la longitud de la cadena
	
	
	expreposfija(infija, tam, pila, posfija);
	
	
	return 0;
}


int prioridad(char simbol){  //Primera función, para saber la prioridad
	int pri = 0;
	
	if(simbol =='('){
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
		char auxsimbo; // Se puede cambiar luego por la cadena
		int priori;
		int i,j,k; //La j lo utilizo para la pila "Tener en cuenta en donde utilizarlo, no es lo mismo que i"
		
		j=0; k=0;
		for(i=0; i<=longitud; i++){
			auxsimbo = infi[i];
			if(auxsimbo == '('){   //
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
			
			else if(auxsimbo>='a' && auxsimbo<= 'z'){  //Se utiliza esto de >= con letras ya que tiene importancia segun ASCII
				exprepos[k] = auxsimbo;
				k++;
			}
			
			else{
				priori = prioridad(auxsimbo);
				//printf("priori %i\n", priori);
				//printf("Prioridad %i\n", prioripila);
				while(j>0 && (priori <= prioridad(pili[j]))){
					printf("La prioridad es %i",prioridad(pili[j]));
					exprepos[k] = pili[j];
					k++;
					j--; // Si se quita de la pila lo tenemos que reducir
				}
				j++;
				pili[j] = auxsimbo;
			}
		}
		//Cuando termina el ciclo for, puede que quede algo en la pila
		// Y con esto lo sacamos
		while(j>0){  
			exprepos[k] = pili[j];
			k++;
			j--;
		}
		printf("La k es %i", k);
		exprepos[k-1]=finca;
		printf("La expresión en notacion posfija es; \n");
		for(i=0; i<=k; i++){
			printf("%c", exprepos[i]);
		}
		printf("\n\n");
		for(i=0; i<=k; i++){
			printf("%i =", exprepos[i]);
		}
	}
		
		
		
	
	
	
