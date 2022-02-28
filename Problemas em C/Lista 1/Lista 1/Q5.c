#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
	int ano;
	
	printf("Digite um ano: ");
	scanf("%i", &ano);
	
	if (ano >= 1752) 
		if (ano % 4 == 0) 
			if (ano % 100 == 0)
				if (ano % 400 == 0)
					printf("Eh bissexto\n");
				else
					printf("Nao eh bissexto\n");
	
			else
				printf("Eh bissexto\n");
		else
			printf("Nao eh bissexto\n");
		
	else
		printf("Nao eh bissexto\n");
				
		
	return EXIT_SUCCESS;
}	
