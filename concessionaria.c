/*
    Nome: Raphael Damasceno Rocha de Moraes
    Ra: 156380
    Turma IB - Algoritmos e Estrutura de Dados
    13/10/2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

//Cadastro do registro de vetores
typedef struct
{
    char marca[15];
    char modelo[25];
    int ano;
    char placa[6];
    int quilometragem;
    int numportas;
    char ar[3];
} registroCarro;
registroCarro* Carro[MAX];

//Fun��o de Inser�ao de dados
void insertcad(){

    registroCarro* Car = (registroCarro*) malloc(sizeof(registroCarro));
    FILE* pont_arq;
    //Declara��o das vari�veis de arquivo

    pont_arq= fopen("carros.txt", "a");
    //Abertura de arquivo para escrita ao fim

    //Coleta dos dados para novo cadastro
    printf("Digite os dados solicitados abaixo\n\n");
    printf("Marca:\n");
        fflush(stdin);
         gets(Car->marca);
            fprintf(pont_arq, "%s\n", Car->marca);

    printf("Modelo:\n");
        fflush(stdin);
         gets(Car->modelo);
            fprintf(pont_arq, "%s\n", Car->modelo);

    printf("Ano de Fabricacao:\n");
        fflush(stdin);
         scanf("%d", &Car->ano);
            fprintf(pont_arq, "%d\n", Car->ano);

    printf("Placa:\n");
        fflush(stdin);
         scanf("%s", Car->placa);
            fprintf(pont_arq, "%s\n", Car->placa);

    printf("Quilometragem:\n");
        fflush(stdin);
         scanf("%d", &Car->quilometragem);
            fprintf(pont_arq, "%d\n", Car->quilometragem);

    printf("Numero de portas:\n");
        fflush(stdin);
         scanf("%d", &Car->numportas);
            fprintf(pont_arq, "%d\n", Car->numportas);

    printf("Ar condicionado:\n");
        fflush(stdin);
         scanf("%s", Car->ar);
            fprintf(pont_arq, "%s\n", Car->ar);

    fclose(pont_arq);
    fflush(stdin);
    free(Car);
}

//Fun��o de Altera��o de dados
void altercad(){
    int a, alterint;
    char alterchar[25];
    int i, j;
    char placabase[6], auxString[15];
    FILE* pont_arq;
    FILE* pont_arqnew;
    //Abertura de arquivo para escrita ao fim

    pont_arq = fopen("carros.txt", "r");
    //Abertura de arquivo para leitura

    i=0;
    j=0;

    //Loop para leitura de todos os dados do arquivo e armazenamento no registro de carros
    while(fscanf(pont_arq, "%s", auxString)!= EOF){
        Carro[i]=(registroCarro*) malloc(sizeof(registroCarro));
        strcpy(Carro[i]->marca, auxString);
        fscanf(pont_arq, "%s", Carro[i]->modelo);
        fscanf(pont_arq, "%d", &Carro[i]->ano);
        fscanf(pont_arq, "%s", Carro[i]->placa);
        fscanf(pont_arq, "%d", &Carro[i]->quilometragem);
        fscanf(pont_arq, "%d", &Carro[i]->numportas);
        fscanf(pont_arq, "%s", Carro[i]->ar);
        i++;
        j++;
    }
    fclose(pont_arq);
    Carro[i] = (registroCarro*)malloc(sizeof(registroCarro));
    strcpy(Carro[i]->placa, "1");

    //Leitura da placa de referencia para consulta
    printf("\nDigite a placa para consulta:\n");
    scanf("%s", placabase);
    i=0;
    int aux=j;

    //Compara��o da placa lida com as existentes no registro
    while((strcmp(placabase, Carro[i]->placa) != 0 && i<j )){
        i++;
        aux--;
    }
    if(aux!=0){
        do{


        //Escolha da opcao para alterar
        printf("\n\nQual opcao deseja alterar?:\n");
        printf("============================================\n");
        printf("(1) Marca.       \n");
        printf("(2) Modelo.  \n");
        printf("(3) Ano.\n");
        printf("(4) Quilometragem.\n");
        printf("(5) Numero de portas.\n");
        printf("(6) Ar condicionado.\n");\
        printf("(7) Fim da alteracao.\n");
        printf("============================================\n");
        printf("Digite a opcao desejada:\n");
        printf("\n");
        scanf("%d",&a);


        //Coleta dos novos dados para altera��o
            switch(a){
            case 1:
                printf("============================================\n");
                printf("Digite a nova marca:\n\n");
                scanf("%s", alterchar);
                strcpy(Carro[i]->marca, alterchar);
                printf("Alterado com sucesso!\n");
                printf("============================================\n");

                break;
            case 2:
                printf("============================================\n");
                printf("Digite o novo modelo:\n\n");
                scanf("%s", alterchar);
                strcpy(Carro[i]->modelo, alterchar);
                printf("\nAlterado com sucesso!\n");
                printf("============================================\n");
                break;
            case 3:
                printf("============================================\n");
                printf("Digite o novo ano de fabricacao:\n\n");
                scanf("%d", &alterint);
                Carro[i]->ano = alterint;
                printf("\nAlterado com sucesso!\n");
                printf("============================================\n");
                break;
            case 4:
                printf("============================================\n");
                printf("Digite a nova quilometragem:\n\n");
                scanf("%d", &alterint);
                Carro[i]->quilometragem=alterint;
                printf("\nAlterado com sucesso!\n");
                printf("============================================\n");
                break;
            case 5:
                printf("============================================\n");
                printf("Digite o novo numero de portas:\n\n");
                scanf("%d", &alterint);
                Carro[i]->numportas=alterint;
                printf("\nAlterado com sucesso!\n");
                printf("============================================\n");
                break;
            case 6:
                printf("============================================\n");
                printf("Digite se possui ar condicionado:\n\n");
                scanf("%s", alterchar);
                strcpy(Carro[i]->ar, alterchar);
                printf("\nAlterado com sucesso!\n");
                printf("============================================\n");
                break;
            }
    }while(a!=7);
     int n=0;
     pont_arqnew = fopen("carrosnew.txt", "w");
     //Escrita dos registros j� alterados
     while(n<j){
        fprintf(pont_arqnew, "%s\n", Carro[n]->marca);
        fprintf(pont_arqnew, "%s\n", Carro[n]->modelo);
        fprintf(pont_arqnew, "%d\n", Carro[n]->ano);
        fprintf(pont_arqnew, "%s\n", Carro[n]->placa);
        fprintf(pont_arqnew, "%d\n", Carro[n]->quilometragem);
        fprintf(pont_arqnew, "%d\n", Carro[n]->numportas);
        fprintf(pont_arqnew, "%s\n", Carro[n]->ar);
        n++;
     }

    fclose(pont_arqnew);
    remove("carros.txt");
    rename("carrosnew.txt","carros.txt");
    }
    //Mensagem caso placa seja inexistente
    else{
        printf("\nERRO! Placa nao encontrada!\n\n");
    }
    for(i=0;i<=j;i++)
        free(Carro[i]);
}
void showcad(){
    int i;
    char placabase[6], auxString[15];
    FILE* pont_arq;
    pont_arq = fopen("carros.txt", "r");
    //Abertura de arquivo para leitura

    i=0;

    printf("Digite a placa para consulta:\n");
    scanf("%s", placabase);
    //Leitura da placa base


    //leitura dos dados do arquivo
    while(fscanf(pont_arq, "%s", auxString)!= EOF){
        Carro[i] = (registroCarro*) malloc(sizeof(registroCarro));
        strcpy(Carro[i]->marca, auxString);
        fscanf(pont_arq, "%s", Carro[i]->modelo);
        fscanf(pont_arq, "%d", &Carro[i]->ano);
        fscanf(pont_arq, "%s", Carro[i]->placa);
        fscanf(pont_arq, "%d", &Carro[i]->quilometragem);
        fscanf(pont_arq, "%d", &Carro[i]->numportas);
        fscanf(pont_arq, "%s", Carro[i]->ar);

        //Impressao dos dados
        if(strcmp(placabase, Carro[i]->placa) == 0){
            printf("\n\nDados abaixo:\n");
            printf("%s\n", Carro[i]->marca);
            printf("%s\n", Carro[i]->modelo);
            printf("%d\n", Carro[i]->ano);
            printf("%s\n", Carro[i]->placa);
            printf("%d\n", Carro[i]->quilometragem);
            printf("%d\n", Carro[i]->numportas);
            printf("%s\n", Carro[i]->ar);

            fclose(pont_arq);
            return;
        }
        i++;
    }
    //Caso placa nao exista
    int j=i;
    printf("\nCarro nao encontrado!\n");
     for(i=0;i<j;i++)
        free(Carro[i]);
    fclose(pont_arq);
}
void removecad(){
     int n=0;
    int i, j;
    char placabase[6], auxString[15];
    FILE* pont_arq;
    FILE* pont_arqnew;
    pont_arq = fopen("carros.txt", "r");
    //Abertura do arquivo para leitura

    i=0;
    j=0;
    while(fscanf(pont_arq, "%s", auxString)!= EOF){
        Carro[i]=(registroCarro*)malloc(sizeof(registroCarro));
        strcpy(Carro[i]->marca, auxString);
        fscanf(pont_arq, "%s", Carro[i]->modelo);
        fscanf(pont_arq, "%d", &Carro[i]->ano);
        fscanf(pont_arq, "%s", Carro[i]->placa);
        fscanf(pont_arq, "%d", &Carro[i]->quilometragem);
        fscanf(pont_arq, "%d", &Carro[i]->numportas);
        fscanf(pont_arq, "%s", Carro[i]->ar);
        i++;
        j++;
    }
    fclose(pont_arq);
    Carro[i] = (registroCarro*)malloc(sizeof(registroCarro));
    strcpy(Carro[i]->placa, "1");
    printf("Digite a placa para consulta:\n");
    scanf("%s", placabase);
    i=0;
    int aux=j;
        //Localizacao da placa procurada
    while((strcmp(placabase, Carro[i]->placa) != 0 && i<j )){
        i++;
        aux--;
    }
    if(aux!=0){
        pont_arqnew = fopen("carrosnew.txt", "w");
        //Reescrita dos dados excluindo o selecionado
     while(n<j){
            if(n!=i){
            fprintf(pont_arqnew, "%s\n", Carro[n]->marca);
            fprintf(pont_arqnew, "%s\n", Carro[n]->modelo);
            fprintf(pont_arqnew, "%d\n", Carro[n]->ano);
            fprintf(pont_arqnew, "%s\n", Carro[n]->placa);
            fprintf(pont_arqnew, "%d\n", Carro[n]->quilometragem);
            fprintf(pont_arqnew, "%d\n", Carro[n]->numportas);
            fprintf(pont_arqnew, "%s\n", Carro[n]->ar);
            }
        n++;
     }

    fclose(pont_arqnew);
    remove("carros.txt");
    rename("carrosnew.txt","carros.txt");
    printf("Removido com sucesso!\n");


    }
    else{
            //Caso placa nao exista
        printf("ERRO! Placa nao encontrada!\n");
    }
     for(i=0;i<=j;i++)
        free(Carro[i]);
}
int main(){
    int a;
    //Impressao do menu incial de escolhas
    do{
        printf("============================================\n");
        printf("(1) Inserir novo cadastro de veiculo.       \n");
        printf("(2) Modificar dados de um veiculo.  \n");
        printf("(3) Exibir dados de um veiculo.\n");
        printf("(4) Apagar dados de um veiculo.\n");
        printf("(5) Sair.\n");
        printf("============================================\n");
        printf("Digite a opcao desejada:\n");
        printf("\n");
    scanf("%d", &a);
        //Escolha das op�oes
    switch(a){
    case 1:
        printf("============================================\n");
        insertcad();
        break;

    case 2:
        printf("============================================\n");
        altercad();
        break;

    case 3:
        printf("============================================\n");
        showcad();
        break;

    case 4:
        printf("============================================\n");
        removecad();
        break;

    case 5:
        printf("============================================\n");
        break;
    }
    }while(a!=5);



    return 0;
}
