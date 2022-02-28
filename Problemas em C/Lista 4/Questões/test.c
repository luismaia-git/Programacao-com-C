#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int x, int a);
int isPrime(int x);
void primoMenor(int x, int a);
void primeiroPrimo(int x, int a);

int main (int narg, char *argv[]) {
  int N;
  printf("digite um numero: ");
  scanf("%d", &N);

  int resultadoA= isPrime(N);


  printf("a) ");
  if (resultadoA==1)
    printf("eh primo\n");
  else
    printf("nao eh primo\n");
  
  printf("b) ");
  primoMenor(N, 2);
  printf("\n");

  printf("c) ");
  primeiroPrimo(N, 2);
  printf("\n");




  return EXIT_SUCCESS;
}

int ehPrimo(int x, int a){
  if (a==1){
    return 1;
  }
  
  if (x%a==0) {
    return 0; 
  }
  else{
    ehPrimo(x,a-1);
  }
  
}

int isPrime(int x){
  int result = ehPrimo(x,x-1);
  return result;
}

void primoMenor(int x, int a){
  
  if (a>=x){
    return;
  }
  if(isPrime(a) == 1) { 
    printf("%d ", a);  
  }   
  primoMenor(x, a+1);
}

void primeiroPrimo(int x, int a){

  if (x==0){
    return;
  }
  if (isPrime(a) == 1) { 
    printf("%d ", a); 
    primeiroPrimo(x-1,a+1);
  }
  else
    primeiroPrimo(x,a+1);

}
