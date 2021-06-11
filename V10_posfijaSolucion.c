#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char resPosfija[20], auxPosfija[20]={0};
	char oper[4] = {'+','-','/','*'};
	int longi, i, j;// oper1, oper2;
	float resultado;
	
	printf("Ingrese la expresión posfija");
	scanf("%s", &resPosfija);
	
	longi = strlen(resPosfija);
	
	for (i=0; i<longi; i++){
		auxPosfija[i] = resPosfija[i];
		for (j=0; j<4; j++){
			if (auxPosfija[i] == oper[j]){
				
				if ((i>=3) && (oper[j]=='+')) {
/*					oper1 = atoi(auxPosfija[i-2]);*/
/*					oper2 = atoi(auxPosfija[i-1]);*/
					resultado = (float)auxPosfija[i-2] + (float)auxPosfija[i-1];
					auxPosfija[i-3]= resultado;
					printf("I es : %i, %i---%.1f\n", i, i-3, resultado);
				}
				
				else if ((i>=3) && (oper[j]=='-')) {
					resultado = auxPosfija[i-2] - auxPosfija[i-1];
					auxPosfija[i-3]= resultado;
				}
				
				else if ((i>=3) && (oper[j]=='/')) {
					resultado = auxPosfija[i-2] / auxPosfija[i-1];
					auxPosfija[i-3]= resultado;
				}
				
				else if ((i>=3) && (oper[j]=='*')) {
					resultado = auxPosfija[i-2] * auxPosfija[i-1];
					auxPosfija[i-3]= resultado;
				}
				
			}
		}

	}

	printf("Resultado = %.2f", resultado);
	
	
	return 0;
}

