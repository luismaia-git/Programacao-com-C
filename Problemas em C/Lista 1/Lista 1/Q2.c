#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
	float p, q, r, hip, a, b;
	
	printf("Digite a primeira medida do triangulo: ");
	scanf("%f", &p);

	printf("Digite a segunda medida do triangulo: ");
	scanf("%f", &q);
	
	printf("Digite a terceira medida do triangulo: ");
	scanf("%f", &r);
				
	if ((p > q) && (p > r)){
		hip = p;
		a = q;
		b = r;
		
	}else if ((q > p) && (q > r)){
			hip = q;
			a = p;
			b = r;
			} 	
	else{
		hip = r;
		a = p;
		b = q;
	}
				  
	printf("%.1f\n", hip * hip);
	printf("%.1f\n", a * a);
	printf("%.1f\n", b * b);
			
	if ((hip * hip) == (a * a) + (b * b))
		printf("Eh um triangulo retangulo\n");
	else
		printf("Nao eh um triangulo retangulo\n");	
		
			 	
	return EXIT_SUCCESS;
}
