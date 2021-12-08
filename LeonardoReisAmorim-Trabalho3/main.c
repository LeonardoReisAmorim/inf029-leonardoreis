#include <stdio.h>
#include "recursao.h"

int main(void) {
  int q1;
  printf("\n====================== Q1 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&q1);
  printf("\n%d ",fatorial(q1));

  int q2;
  printf("\n====================== Q2 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&q2);
  printf("\n%d ",fibonacci(q2));

  int q3;
  printf("\n====================== Q3 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&q3);
  printf("\n%d ",inverte(q3));

  int vet[5],i;
  printf("\n====================== Q4 =======================\n");
  for(i=0;i<5;i++){
    printf("\ndigite um numero: ");
    scanf("%d",&vet[i]);
  }
  printf("\n%d ",somaVetor(vet, 5));

  int q5;
  printf("\n====================== Q5 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&q5);
  printf("\n%d ",soma1aN(q5));

  int k,n;
  printf("\n====================== Q6 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&k);
  printf("digite outro numero: ");
  scanf("%d",&n);
  printf("\n%d ",potenciakn(k, n));

  int x,y;
  printf("\n====================== Q8 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&x);
  printf("digite outro numero: ");
  scanf("%d",&y);
  printf("\n%d ",maxDivCom(x, y));

  int n1,n2;
  printf("\n====================== Q10 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&n1);
  printf("digite outro numero: ");
  scanf("%d",&n2);
  printf("\n%d ",multRec(n1, n2));

  int num;
  printf("\n====================== Q15 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&num);
  printf("\n%d ",fatDuplo(num));

  int m,n;
  printf("\n====================== Q29 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&m);
  printf("digite um numero: ");
  scanf("%d",&n);
  printf("\n%d ",h(m, n));
  return 0;
}
