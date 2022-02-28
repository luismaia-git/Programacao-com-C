#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
//BubbleSort (troca)
void troca(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

//BubbleSort
void bubbleSort(int v[], int n)
{
   int trocado;
   for (int i = 0; i < n-1; i++)
   {
     trocado = 0;

     for (int j = 0; j < n-i-1; j++)
     {
        if (v[j] > v[j+1])
        {
           troca(&v[j], &v[j+1]);
           trocado = 1;
        }
     }
 
     // se não tiver nenhuma troca mais, entao ele para
     if (trocado == 0)
        return;
   }
}
  

//selectionSort
void selectionSort(int v[], int n) {
  int i, j , min , aux;

  for (int i = 0; i < (n-1); i++){
    

    min = i;
    for (int j = i+1; j < n; j++){
      if (v[j] < v[min]) {
          min = j;
      }
    }
    

    if (i != min) {
      aux = v[i];
      v[i] = v[min];
      v[min] = aux;
    }
  }

}

//CombSort

int encontrar(int gap) { 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 
  
void combSort(int a[], int n) { 
    int gap = n; 
  
    int trocado = 1; 
  
    while (gap != 1 || trocado == 1) { 
        gap = encontrar(gap); 
        
        trocado = 0; 
  
        for (int i=0; i<n-gap; i++) { 
            if (a[i] > a[i+gap]) { 
                troca(&a[i], &a[i+gap]); 
                trocado = 1; 
            } 
        } 
    } 
} 

//insertion
void insertionSort(int v[], int n) {
    int aux, i;
    for (int j = 1; j < n; j++) {
        aux = v[j];
        i = j-1;
        while ((i >= 0) && (v[i] > aux)) {
            v[i+1] = v[i];
            i = i - 1;
        }
        v[i+1] = aux;
    }
}

void imprime_vetor(int v[], int n){
  for(int i=0; i<n; i++){
    printf("[%d]%d ", i, v[i]);
  }
  printf("\n");
}



//main
int main (int narg, char *argv[]) {

    clock_t tempo_inicio, tempo_final;
    double tempo_totalBubble = 0, tempo_totalInsertion = 0, tempo_totalComb = 0, tempo_totalSelection = 0;
    int vetor1[N], vetor2[N], vetor3[N], vetor4[N], k;
    

    srand(time(NULL));
    
    k = 300;

    for(int l=0; l < k; l++ ){

      for(int i=0; i < N; i++){
        vetor1[i] = rand()%(100*N);
        vetor2[i] = vetor1[i];
        vetor3[i] = vetor1[i];
        vetor4[i] = vetor1[i];
      }


      // SE NÃO COMENTAR OS ALGORITMOS BUBBLE, INSERTION E SELECTION, VAI DEMORAR MUITO A ORDENAÇÃO,
      // O COMB LEVA EM MEDIA 4 SEGUNDOS
      tempo_inicio = clock(); 
      bubbleSort(vetor1, N);
      tempo_final = clock();
      tempo_totalBubble = tempo_totalBubble + (long double)(tempo_final - tempo_inicio)/CLOCKS_PER_SEC;
      

      tempo_inicio = clock(); 
      insertionSort(vetor2, N);
      tempo_final = clock();
      tempo_totalInsertion = tempo_totalInsertion + (long double)(tempo_final - tempo_inicio)/CLOCKS_PER_SEC;
      

      tempo_inicio = clock(); 
      selectionSort(vetor3, N);
      tempo_final = clock();
      tempo_totalSelection = tempo_totalSelection + (long double)(tempo_final - tempo_inicio)/CLOCKS_PER_SEC;
      
    
      tempo_inicio = clock(); 
      combSort(vetor4, N);
      tempo_final = clock();
      tempo_totalComb = tempo_totalComb + (long double)(tempo_final - tempo_inicio)/CLOCKS_PER_SEC;
      

    }
    
    printf("Tempo do Bubble Sort:    %.4f segundos.\n", tempo_totalBubble);
    printf("Tempo do Insertion Sort: %.4f segundos.\n",tempo_totalInsertion);
    printf("Tempo do Selection Sort: %.4f segundos.\n",tempo_totalSelection);
    printf("Tempo do Comb Sort:      %.4f segundos.\n",tempo_totalComb);

    
  return EXIT_SUCCESS;
}