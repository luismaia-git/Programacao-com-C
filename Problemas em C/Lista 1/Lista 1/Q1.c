#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
	float num, dem, result;
	
	printf("Digite o numerador: ");
	scanf("%f", &num);
	
	printf("Digite o denominador: ");
	scanf("%f", &dem);
	
	if (dem == 0) 
	printf("Indefinido\n");
	else {
		result = num / dem;
		printf("O resultado da divisao eh %.1f\n", result);
	}		
	return EXIT_SUCCESS;
}	
