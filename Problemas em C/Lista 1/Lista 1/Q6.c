#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
	int dia_atual, mes_atual, ano_atual;
	int dia_nasc, mes_nasc, ano_nasc;
	
	printf("Digite o dia atual: ");
	scanf("%i", &dia_atual);	

	printf("Digite o mes atual: ");
	scanf("%i", &mes_atual);

	printf("Digite o ano atual: ");
	scanf("%i", &ano_atual);

		
	printf("Digite o dia de nascimento: ");
	scanf("%i", &dia_nasc);	

	printf("Digite o mes de nascimento: ");
	scanf("%i", &mes_nasc);

	printf("Digite o ano de nascimento: ");
	scanf("%i", &ano_nasc);
	
	
	if (ano_atual - ano_nasc < 16)
		printf("Nao eh eleitor\n");
	
	if (ano_atual - ano_nasc == 16)
		if (mes_atual > mes_nasc)
			printf("Eh eleitor facultativo\n");
		else if	(mes_atual == mes_nasc)
				if (dia_nasc <= dia_atual)
					printf("Eh eleitor facultativo\n");
				else
					printf("Nao eh eleitor\n");		
	
	
	if (ano_atual - ano_nasc == 17 || mes_atual - mes_nasc > 65)
		printf("Eh eleitor facultativo\n");
	
	if (ano_atual - ano_nasc == 18)
		if (mes_atual > mes_nasc)
			printf("Eh eleitor\n");
		else if	(mes_atual == mes_nasc)
				if (dia_nasc <= dia_atual)
					printf("Eh eleitor\n");
				else
					printf("Eh eleitor facultativo\n");		
				
	
	if (ano_atual - ano_nasc > 18 && ano_atual - ano_nasc < 65)
		printf("Eh eleitor\n");
	
	if (mes_atual - ano_nasc == 65)
		if (mes_atual > mes_nasc)
			printf("Eh eleitor facultativo\n");
		else if	(mes_atual == mes_nasc)
				if (dia_nasc <= dia_atual)
					printf("Eh eleitor facultativo\n");
				else
					printf("Eh eleitor\n");		
	
	
	return EXIT_SUCCESS;
}	