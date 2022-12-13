#include "SelectionSort.h"

void swapValues( int* const a, int* const b){
  int t = *a;
  *a = *b;
  *b = t;
}

bool descending(const int a, const int b){
  return(a >= b);
}

bool ascending(const int a, const  int b){
  return (a < b);
}

void selectionSort(int* const numbers, const int n, bool (*order)(const int, const int) ){
  for(int i = 0; i < n-1; i++){
    int min = i;
    
    for(int j = i+1; j < n; j++){
      if((*order)(numbers[j],numbers[min])){
        min = j;
      }
    }
    if(min != i){
      swapValues(&numbers[i], &numbers[min]);
    }
  }
}
