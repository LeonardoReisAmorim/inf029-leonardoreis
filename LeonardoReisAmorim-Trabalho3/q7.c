#include <stdio.h>

/* 8 - máximo divisor comum dos inteiros x e y é o maior inteiro que é divisível por x e y. Escreva uma função recursiva mdc em C,
que retorna o máximo divisor comum de x e y. O mdc de x e y é definido como segue: se y é igual a 0, então mdc(x,y) é x;
caso contrário, mdc(x,y) é mdc (y, x%y), onde % é o operador resto.*/
int maxDivCom(int a, int b) {
	if( b == 0) {
		return a;
	}
	return maxDivCom(b, a % b);
}

int main(void) {
    int x,y;
  printf("\n====================== Q8 =======================\n");
  printf("digite um numero: ");
  scanf("%d",&x);
  printf("digite outro numero: ");
  scanf("%d",&y);
  printf("\n%d ",maxDivCom(x, y));
    return 0;
}