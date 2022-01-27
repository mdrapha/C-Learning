#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  MAX 100


void removespace(char* exp){
    int i=0, j=0;
    char vet[100];
  int n= strlen(exp);
    for(i=0;i<n;i++){
      if(exp[i]==' '){
      continue;
      }else{
      vet[j]=exp[i];
      j++;
      }
    }

  printf("%s", vet);

}

int main(){
  char exp[100];

  gets(exp);
  removespace(exp);

  return 0;
}
