#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



typedef struct
{
    char Nome[25];
    int Mes;
    char Produto[30];
    int  qnt;

}regCliente;
regCliente* Cliente;



void totvendas(int n, regCliente* Cliente)
{
int i, month, j=0, totalvendas=0;
    
    printf("(1) Mes das vendas.\n");
            printf("============================================\n");
        printf("(1) Janeiro\n");
        printf("(2) Fevereiro\n");
        printf("(3) Marco\n");
        printf("(4) Abril\n");
        printf("(5) Maio\n");
        printf("(6) Junho\n");
        printf("(7) Julho \n");
        printf("(8) Agosto\n");
        printf("(9) Setembro\n");
        printf("(10) Outubro\n");
        printf("(11) Novembro\n");
        printf("(12) Dezembro\n");
        printf("============================================\n");
        printf("Digite o numero da opcao desejada:\n");
        printf("\n");
        scanf("%d", &month);
        int aux;

        while(j<n){
        aux= (Cliente+j)->Mes;

            if(month==aux){

                totalvendas+= (Cliente+j)->qnt;
            }
            j++;
        }
        printf("============================================\n");
         printf("Total:\n");
        printf("\n %d \n", totalvendas);
}

void totvpc(int n, regCliente* Cliente)
{

int i, month, j=0, totalvendas=0;
char client[25], product[30];


    printf("(1) Mes das vendas.\n");
            printf("============================================\n");
        printf("(1) Janeiro\n");
        printf("(2) Fevereiro\n");
        printf("(3) Marco\n");
        printf("(4) Abril\n");
        printf("(5) Maio\n");
        printf("(6) Junho\n");
        printf("(7) Julho \n");
        printf("(8) Agosto\n");
        printf("(9) Setembro\n");
        printf("(10) Outubro\n");
        printf("(11) Novembro\n");
        printf("(12) Dezembro\n");
        printf("============================================\n");
        printf("Digite o numero da opcao desejada:\n");
        printf("\n");
        scanf("%d", &month);
        printf("(2) Cliente.\n");
            printf("============================================\n");
        scanf("%s", &client);
        printf("(3) Produto.\n");
        printf("============================================\n");
        scanf("%s",&product);
        int aux;
        int erro=0;
        while(j<n){

            if(month==(Cliente+j)->Mes && (strcmp(client,(Cliente+j)->Nome)==0) && (strcmp(product,(Cliente+j)->Produto)==0)){
                erro++;
                totalvendas+=(Cliente+j)->qnt;
            }
            j++;
        }
        if(erro!=0){
        printf("============================================\n");
        printf("Total:\n");
        printf("\n %d \n", totalvendas);
        }
        else{
         printf("============================================\n");
        printf("\nNenhum dado encontrado.\n");
        }
}

void totvp(int n, regCliente* Cliente){
int i, j;
char nomes[n][30], nrep[n][30], aux[30];

    //passagem dos nomes de produtos para um vetor secundario
    for(i=0;i<n;i++){
        strcpy(nomes[i],(Cliente+i)->Produto);
    }

    //ordenacao alfabetica do vetor
    for (i=1;i<n;i++)
    {
        for (j=1;j<n;j++)
        {
            if (strcmp(nomes[j - 1], nomes[j]) > 0)
            {
                strcpy(aux, nomes[j - 1]);
                strcpy(nomes[j - 1], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }

    //Eliminacao dos itens repetidos
    strcpy(nrep[0],nomes[0]);
    j=1;
    for(i=0;i<n;i++)
    {

        if((strcmp(nomes[i],nomes[i+1])!=0))
        {
                strcpy(nrep[j],nomes[i+1]);
                j++;
        }

    }
    j=j-1;
   int total=0;
   //Calculo dos totais vendidos
    for(i=0;i<j;i++)
    {   total=0;
        for(int k=0;k<n;k++)
        {
            if((strcmp(nrep[i],(Cliente+k)->Produto)==0))
            {
                total+= (Cliente+k)->qnt;
            }
        }
        printf("\n%s: %d\n", nrep[i], total);
    }
}

void totvc(int n, regCliente* Cliente){
int i, j;
char nomes[n][25], nrep[n][25], aux[25];


    //passagem dos nomes de produtos para um vetor secundario
    for(i=0;i<n;i++){
        strcpy(nomes[i],(Cliente+i)->Nome);
    }

    //ordenacao alfabetica do vetor
    for (i=1;i<n;i++)
    {
        for (j=1;j<n;j++)
        {
            if (strcmp(nomes[j - 1], nomes[j]) > 0)
            {
                strcpy(aux, nomes[j - 1]);
                strcpy(nomes[j - 1], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }

    //Eliminacao dos itens repetidos
    strcpy(nrep[0],nomes[0]);
    j=1;
    for(i=0;i<n;i++)
    {

        if((strcmp(nomes[i],nomes[i+1])!=0))
        {
                strcpy(nrep[j],nomes[i+1]);
                j++;
        }

    }
    j=j-1;
   int total=0;
   //Calculo dos totais vendidos
    for(i=0;i<j;i++)
    {   total=0;
        for(int k=0;k<n;k++)
        {
            if((strcmp(nrep[i],(Cliente+k)->Nome)==0))
            {
                total+= (Cliente+k)->qnt;
            }
        }
        printf("\n%s: %d\n", nrep[i], total);
    }
   
}


int main(){
    int a, i, n;


         printf("\n\nResponda os dados a seguir:\n");
        printf("============================================\n");
        printf("(1) Quantidade de registros.       \n");
            scanf("%d",&n);
        regCliente* Cliente;
        Cliente=(regCliente*)malloc(n * sizeof(regCliente));

    //Impressao do menu incial de escolhas
     for(i=0;i<n; i++){


        printf("(2) Nome do cliente.  \n");
            scanf("%s", (Cliente+i)->Nome);
        printf("(3) Mes da venda.\n");
        printf("============================================\n");
        printf("(1) Janeiro\n");
        printf("(2) Fevereiro\n");
        printf("(3) Marco\n");
        printf("(4) Abril\n");
        printf("(5) Maio\n");
        printf("(6) Junho\n");
        printf("(7) Julho \n");
        printf("(8) Agosto\n");
        printf("(9) Setembro\n");
        printf("(10) Outubro\n");
        printf("(11) Novembro\n");
        printf("(12) Dezembro\n");
        printf("============================================\n");
        printf("Digite o numero da opcao desejada:\n");
        printf("\n");
            scanf("%d", &(Cliente+i)->Mes);
        printf("(4) Nome do produto.\n");
            scanf("%s", (Cliente+i)->Produto);
        printf("(5) Quantidade de produtos.\n");
            scanf("%d", &(Cliente+i)->qnt);
        printf("(6) Fim do cadastro.\n");
        printf("============================================\n");
        printf("\n");


    };

    do{
        printf("============================================\n");
        printf("(1) Total de vendas num dado mes.       \n");
        printf("(2) Total de vendas de um determinado produto num dado mes para um determinado cliente.  \n");
        printf("(3) Total de vendas de cada produto (em todos os meses).\n");
        printf("(4) Total vendido para cada cliente.\n");
        printf("(5) Fim.\n");
        printf("============================================\n");
        printf("Digite a opcao desejada:\n");
        printf("\n");
    scanf("%d", &a);
        switch(a){
    case 1:
        printf("============================================\n");
        totvendas(n,Cliente);
        break;

    case 2:
        printf("============================================\n");
        totvpc(n,Cliente);
        break;

    case 3:
        printf("============================================\n");
        totvp(n,Cliente);
        break;

    case 4:
        printf("============================================\n");
        totvc(n, Cliente);
        break;

    case 5:
        printf("============================================\n");
        break;
    }
    }while(a!=5);

free (Cliente);
return 0;
}
