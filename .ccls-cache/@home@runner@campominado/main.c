/**************************************************************************************
* PROG:             campo minado                                                      *
* AUTOR:            jesse silva                                                       *
* DATA:             14/06/2023                                                        *
* ATUALIZADO EM:    28/06/2023  01:12                                                 *
**************************************************************************************/

/**=================================================================================**/
/**--- Bibliotecas ---**/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>   // para usar a funçao rand
#include<unistd.h> // para usar a funçao sleep

/**=================================================================================**/
/**--- Variaveis Globais ---**/


/**=================================================================================**/
/**--- Constantes ---**/

#define l 8  //largura
#define c 10 //comprimento
#define BOMB 4 // nivel de bombas no jogo
#define r 0 // randomizador = c-10;

/**=================================================================================**/
/**--- Protótipo das funções ---**/

int randomizador(int ramdom[l][c]);
int numeros(int ramdom[l][c],int i,int j);
void printado(int ramdom[l][c],int i,int j,int clique[l][c]);
void structure(int ramdom[l][c]);

/**=================================================================================**/
/**--- Função principal ---**/

int main()
{
    int ramdom[l][c]={0};
    
    structure(ramdom);   
}
/**=================================================================================**/
/**--- Desenvolvimento da Funçao ---**/

int randomizador(int ramdom[l][c])
{
    int i,j,a0,b0,
        num1[l]={0,},
        num2[c]={0,};
    
    srand(time(NULL));

   for(i=0;i<BOMB;i++)
   {
        for(j=0;j<BOMB;j++)
        {
            num1[i]=rand()%(10+r); // gera numeros de 0 a 9
            num2[j]=rand()%(10+r); // gera numeros de 0 a 9

            a0=num1[i];
            b0=num2[j];

            ramdom[a0][b0] = 1;
        }
   }
  return ramdom[l][c];
}

//////////////////////////////////////////////////////////////////////////////////////

int numeros(int ramdom[l][c],int i,int j)
{
    int contador=0,
    quant[l][c]={0};
    
    if(ramdom[i][j]!=1)
    {
        contador=0;
                
        if(i>0 && j>0 && ramdom[i-1][j-1]==1) contador++;
        if(i>0 && ramdom[i-1][j]==1)contador++;
        if(i>0 && j<c-1 &&ramdom[i-1][j+1]==1)contador++;
        if(j>0 && ramdom[i][j-1]==1)contador++;
        if(j<c-1 &&ramdom[i][j+1]==1)contador++;
        if(i<l-1 && j>0 && ramdom[i+1][j-1]==1)contador++;
        if(i<l-1 && ramdom[i+1][j]==1)contador++;
        if(i<l-1 && j<c-1 && ramdom[i+1][j+1]==1)contador++;
                
        quant[i][j]=contador;
                
        switch(quant[i][j])
        {
        case 0:
            printf("|   ");
            break;
        case 1:
            printf("| 1 ");
            break;
        case 2:
            printf("| 2 ");
            break;
        case 3:
            printf("| 3 ");
            break;
        case 4:
            printf("| 4 ");
            break;
        case 5:
            printf("| 5 ");
           break;
        case 6:
            printf("| 6 ");
            break;
        case 7:
            printf("| 7 ");
            break;
        case 8:
            printf("| 8 ");
            break;
        default:
            break;
        }
    }
        
    
}

//////////////////////////////////////////////////////////////////////////////////////

void printado(int ramdom[l][c],int i,int j,int clique[l][c])
{
    if(ramdom[i][j]==1)
    printf("| o ");
    else
    numeros(ramdom,i,j);
}

//////////////////////////////////////////////////////////////////////////////////////

void structure(int ramdom[l][c]) // corpo inicial
{
    int op=0,you_lose,
        num,let;
    int clique[l][c]={0};
    
    do
    {
        system("clear");
        char letra = 'A';
    
        printf("\t");
        for(int a=0;a<c;a++)
            {
               printf("  %c ",letra);
               letra++;
            }
            printf("\n");
    
        for(int i=0;i<l;i++)
        {
    
            printf("\t");
            for(int q=0;q<c;q++)
            {
               printf("----");
            }
            printf("-\n");
            printf(" %d",i+1);
            printf("\t");
    
            for(int j=0;j<c;j++)
            {
                printf("|   ");
            }
            printf("|\n");
        }
        printf("\t");
    
        for(int w=0;w<c;w++)
            {
               printf("----");
            }
            printf("-\n");

        printf("\n");
        printf(" 1 - Jogar\n");
        printf(" 2 - Recomeçar\n");
        printf(" 3 - sair\n");
        printf(" Escolha uma das opcoes acima: ");
        scanf("%d",&op);
        
        if(op==1)
        {
            printf(" Escolha o numero: ");
            scanf("%d",&num);   
            printf(" Escolha a letra: ");
            scanf("%d",&let);
            let = toupper(let);
            
            system("clear");
            //////////////////////////////////////////////////////////////////////////
            /*                    AQUI O JOGO REALMENTE COMEÇA !!!!                 */
            //////////////////////////////////////////////////////////////////////////
            
            do{
                num-=1;
                let-=65;
                
                clique[num][let]=1;
                
                char letra = 'A';
            
                printf("\t");
                for(int a=0;a<c;a++)
                    {
                       printf("  %c ",letra);
                       letra++;
                    }
                    printf("\n");
            
                for(int i=0;i<l;i++)
                {
            
                    printf("\t");
                    for(int q=0;q<c;q++)
                    {
                       printf("----");
                    }
                    printf("-\n");
                    printf("   %d",i+1);
                    printf("\t");
            
                    for(int j=0;j<c;j++)
                    {
                        printado(ramdom,i,j,clique);
                    }
                    printf("|\n");
                }
                printf("\t");
            
                for(int w=0;w<c;w++)
                    {
                       printf("----");
                    }
                    printf("-\n");
                    
            printf("\n");        
            printf(" Escolha o numero: ");
            scanf(" %d",&num);   
            printf(" Escolha a letra: ");
            scanf(" %d",&let);
            let = toupper(let);    
            
            }while(you_lose!=0);
        }
    }while(op!=1&&op!=2&&op!=3);
}