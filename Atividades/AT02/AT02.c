#include <stdio.h>

int main ()
{
	int op,i=1;
	float n1,n2;
	while(i!=0)
	{
		printf("----------------------- C A L C U L A D O R A ----------------------------------\n\n");
	
        printf("\ndigite um numero:  ");
          scanf("%f",&n1);
          printf("\ndigite outro numero:  ");
          scanf("%f",&n2);
      
          printf("\ndigite a operacao:\n 0 - Sair\n 1- Somar:\n 2-subtracao:\n 3-multiplicacao:\n 4-divisao:\n ");
          scanf("%d",&op);
        
          switch(op)
          {
          	case 1:
          		printf("\na adicao entre %.2f e %.2f e: %.2f\n",n1,n2,n1+n2);
          		break;
          		
          	case 2:
          		printf("\na subtracao entre %.2f e %.2f e: %.2f\n",n1,n2,n1-n2);
          		break;
          		
          	case 3:
                printf("\na multiplicacao entre %.2f e %.2f e: %.2f\n",n1,n2,n1*n2);
          		break;
          		
          	case 4:
          		printf("\na divisao entre %.2f e %.2f e: %.2f\n",n1,n2,n1/n2);
          		break;
          		
          	case 0:
          	    printf("\nSaindo do programa\n");
          	    i = 0;
          	    break;
          		
          	default: 
          		printf("\ncomando invalido\n");
          }
          if(i!=0){
              printf("deseja sair do sistema?\n0 - sim\n1 - nao\n");
            scanf("%d",&i);
          }
          
    }
  return 0;
}