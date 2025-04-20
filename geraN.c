#include <stdio.h>
#include <stdlib.h>
#include "funcsSort.h"


int main(int argc, char *argv[]){
  unsigned int i, val, N;
  if(argc == 2){
    N = val = atoi(argv[1]);
  } else {
    if(argc == 3){
      N = atoi(argv[1]);
      val = atoi(argv[2]);
    } else {
      printf("Uso: geraN <numero de valores a serem gerados> [limite superior para os valores]\n");
      exit(0);
    }
  }

  val++;
  for(i = 0; i < N; i++)
    printf("%u\n", (unsigned int) rand() % val);  

  return 0;
}
