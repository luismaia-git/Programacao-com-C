/* 
Implemente o solicitado abaixo, com relação a números primos:
a) Uma função que determine se um número é ou não primo.
b) Um programa para imprimir todos os números primos menores que um valor x, fornecido via teclado,
utilizando a função implementada em (a).
c) Um programa para imprimir os primeiros n números primos, onde n é fornecido via teclado, utilizando
a função implementada em (a).
*/

#include <stdio.h>
#include <stdlib.h>


int isPrime(int x);

int main (int narg, char *argv[]) {
int x;
  
  //entrada de dados
  printf("Digite o valor de x: ");
  scanf("%d", &x);
  
  //item a)
  if (isPrime(x)) 
    printf("a) O numero %d eh primo\n", x);
  else
    printf("a) O numero %d não eh primo\n", x);
  
  //item b)
  int i = 2;
    printf("b) ");
    while(i < x) {
        if(isPrime(i)) {
          printf("%d ", i);
        }
        i++;
    }
    printf("\n");
  
  //item c)
    int j = 2;
    printf("c) ");
    while(x) {
        if(isPrime(j)) {
            printf("%d ", j);
            x--;
        }
        j++;
    }

  printf("\n");
  return EXIT_SUCCESS;

};

//função pra saber se x é primo
int isPrime(int x){
  
  if(x < 2) {
    return 0;
  }

  if(x == 2) {
    return 1;
  }

  for(int i = 2; i < x; i++) {
    if(x % i == 0) {
        return 0;
    }
  }

  return 1;

}