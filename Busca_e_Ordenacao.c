#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*  Disciplina: Estrutura de Dados - DCC302
    Professor: Filipe Dwan.
    Alunos: Diego Costa;
           Talles Bezerra.
/*

/* Declaração das funções */
void menu();
void gerarNumeros();
void salvarTXT(int v[], char nomeDoArquivo[], int tam);
void leituraArquivos(char nomeDoArquivo[], int* refVet, int tam);
int selectionSort(int *vetor, int tam);
int insertionSort(int *vetor, int tam);
int bubbleSort(int *vetor, int tam);
int heapSort(int *vetor, int tam);
int mergeSort(int *vetor, int inicio, int fim);
int quickSort(int *vetor, int inicio, int fim);
int radixSort(int *vetor, int tam);
int buscaSequencial(int *vetor, int tam, int valor);
int buscaBinaria(int *vetor, int tam, int valor);
double compMerge = 0, compQuick = 0, trocaQuick = 0;
int flag_numeros_gerados = 0; //flag avisando se os numeros aleatorios foram gerados
void menu(){
    int vetorCem[100];
    int vetorMil[1000];
    int vetorDezMil[10000];
    int vetorCemMil[100000];
    int tam,resultBuscaB, resultBuscaS, valor;
    int op;
    printf("\t\t\t Escolha uma opcao para busca e ordenacao:\n");
    printf("\t0 - Sair do algoritmo\n");
    printf("\t1 - Gerar sequencia de numeros para ordenacao e busca.\n");
    printf("\t2 - Ordenar utilizando selection sort.\n");
    printf("\t3 - Ordenar utilizando insertion sort.\n");
    printf("\t4 - Ordenar utilizando bubble sort.\n");
    printf("\t5 - Ordenar utilizando heap sort.\n");
    printf("\t6 - Ordenar utilizando merge sort.\n");
    printf("\t7 - Ordenar utilizando quick sort.\n");
    printf("\t8 - Ordenar utilizando radix sort.\n");
    printf("\t9 - Fazer busca utilizando busca sequencial.\n");
    printf("\t10 - Fazer busca utilizando busca binaria.\n");
    scanf("%d",&op);
    switch(op){
        case 0:
            exit(0);
            break;
        case 1 :
            flag_numeros_gerados = 1;//Caso a opção de geração de números tenha sido selecionada a flag recebe 1
            gerarNumeros();
            system("pause"); system("cls");
            printf("\n");
            menu();
            break;
        case 2:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: SELECTION SORT\n");
            leituraArquivos("vetorCem.txt", vetorCem, 100); selectionSort(vetorCem, 100);
            salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorMil.txt", vetorMil, 1000); selectionSort(vetorMil, 1000);
            salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000); selectionSort(vetorDezMil, 10000);
            salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000); selectionSort(vetorCemMil, 100000);
            salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100); printf("\n");
            system("pause"); system("cls");
            menu();
            break;
        case 3:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: INSERTION SORT\n");
            leituraArquivos("vetorCem.txt", vetorCem, 100); insertionSort(vetorCem, 100);
            salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorMil.txt", vetorMil, 1000); insertionSort(vetorMil, 1000);
            salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000); insertionSort(vetorDezMil, 10000);
            salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000); insertionSort(vetorCemMil, 100000);
            salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100); printf("\n");
            system("pause"); system("cls");
            menu();
            break;
        case 4:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: BUBBLE SORT\n");
            leituraArquivos("vetorCem.txt", vetorCem, 100); bubbleSort(vetorCem, 100);
            salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorMil.txt", vetorMil, 1000); bubbleSort(vetorMil, 1000);
            salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000); bubbleSort(vetorDezMil, 10000);
            salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000); bubbleSort(vetorCemMil, 100000);
            salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100); printf("\n");
            system("pause"); system("cls");
            menu();
            break;
        case 5:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: HEAP SORT\n");
            leituraArquivos("vetorCem.txt", vetorCem, 100); heapSort(vetorCem, 100);
            salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorMil.txt", vetorMil, 1000); heapSort(vetorMil, 1000);
            salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000); heapSort(vetorDezMil, 10000);
            salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000); heapSort(vetorCemMil, 100000);
            salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100); printf("\n");
            system("pause"); system("cls");
            menu();
            break;
        case 6:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: MERGE SORT\n");
            compMerge = 0; leituraArquivos("vetorCem.txt", vetorCem, 100);
            mergeSort(vetorCem, 0, 100-1); salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100);
            printf("Tamanho: 100\n");
            printf("Quant. de Comparacoes: %.0f\n\n",compMerge);
            compMerge = 0; leituraArquivos("vetorMil.txt", vetorMil, 1000);
            mergeSort(vetorMil, 0, 1000-1); salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100);
            printf("Tamanho: 1000\n");
            printf("Quant. de Comparacoes: %.0f\n\n",compMerge);
            compMerge = 0; leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000);
            mergeSort(vetorDezMil, 0, 10000-1); salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100);
            printf("Tamanho: 10000\n");
            printf("Quant. de Comparacoes: %.0f\n\n",compMerge);
            compMerge = 0; leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000);
            mergeSort(vetorCemMil, 0, 100000-1); salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100);
            printf("Tamanho: 100000\n");
            printf("Quant. de Comparacoes: %.0f\n\n",compMerge);
            system("pause"); system("cls");
            menu();
            break;
        case 7:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: QUICK SORT\n");
            compQuick = 0; trocaQuick = 0; leituraArquivos("vetorCem.txt", vetorCem, 100);
            quickSort(vetorCem, 0, 100-1); salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100);
            printf("Tamanho: 100\n");
            printf("Quant. de Comparacoes: %.0f\n",compQuick);
            printf("Quant. de Trocas: %.0f\n\n",trocaQuick);
            compQuick = 0; trocaQuick = 0; leituraArquivos("vetorMil.txt", vetorMil, 1000);
            quickSort(vetorMil, 0, 1000-1); salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100);
            printf("Tamanho: 1000\n");
            printf("Quant. de Comparacoes: %.0f\n",compQuick);
            printf("Quant. de Trocas: %.0f\n\n",trocaQuick);
            compQuick = 0; trocaQuick = 0; leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000);
            quickSort(vetorDezMil, 0, 10000-1); salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100);
            printf("Tamanho: 10000\n");
            printf("Quant. de Comparacoes: %.0f\n",compQuick);
            printf("Quant. de Trocas: %.0f\n\n",trocaQuick);
            compQuick = 0; trocaQuick = 0; leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000);
            quickSort(vetorCemMil, 0, 100000-1); salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100);
            printf("Tamanho: 100000\n");
            printf("Quant. de Comparacoes: %.0f\n",compQuick);
            printf("Quant. de Trocas: %.0f\n\n",trocaQuick);
            system("pause"); system("cls");
            menu();
            break;
        case 8:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: RADIX SORT\n");
            leituraArquivos("vetorCem.txt", vetorCem, 100); radixSort(vetorCem, 100);
            salvarTXT(vetorCem, "vetorCemOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorMil.txt", vetorMil, 1000); radixSort(vetorMil, 1000);
            salvarTXT(vetorCem, "vetorMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000); radixSort(vetorDezMil, 10000);
            salvarTXT(vetorCem, "vetorDezMilOrdenado.txt", 100); printf("\n");
            leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000); radixSort(vetorCemMil, 100000);
            salvarTXT(vetorCem, "vetorCemMilOrdenado.txt", 100); printf("\n");
            system("pause"); system("cls");
            menu();
            break;
        case 9:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: BUSCA SEQUENCIAL\n");
            printf("Busque um valor: "); scanf("%d", &valor);
            printf("Tamanho do vetor: "); scanf("%d", &tam);
            if(tam==100){
                leituraArquivos("vetorCem.txt", vetorCem, 100);
                resultBuscaS = buscaSequencial(vetorCem, 100, valor);
            }
            else if(tam==1000){
                leituraArquivos("vetorMil.txt", vetorMil, 1000);
                resultBuscaS = buscaSequencial(vetorMil, 1000, valor);
            }
            else if(tam==10000){
                leituraArquivos("vetorDezMil.txt", vetorDezMil, 10000);
                resultBuscaS = buscaSequencial(vetorDezMil, 10000, valor);
            }
            else if(tam==100000){
                leituraArquivos("vetorCemMil.txt", vetorCemMil, 100000);
                resultBuscaS = buscaSequencial(vetorCemMil, 100000, valor);
            }
            else{
                printf("Tamanho invalido\n");
                system("pause"); system("cls");
                menu();
            }
            if(resultBuscaS!=(-1))
                printf("Valor %d encontrado na posicao %d\n",valor,resultBuscaS);
            else
                printf("Valor %d nao esta no vetor\n",valor);
            system("pause"); system("cls");
            menu();
            break;
        case 10:
            system("cls");
            if(flag_numeros_gerados == 0){
                printf("Nao ha numeros para ordenar. Retorne ao menu e selecione a opcao 1.\n");
                printf("Aperte qualquer tecla para regressar ao menu.\n");
                system("pause");
                system("cls");
                menu();
                break;
            }
            printf("ALGORITMO: BUSCA BINARIA\n");
            printf("Busque um valor: "); scanf("%d", &valor);
            printf("Tamanho do vetor: "); scanf("%d", &tam);
            if(tam==100){
                leituraArquivos("vetorCemOrdenado.txt", vetorCem, 100);
                resultBuscaB = buscaBinaria(vetorCem, 100, valor);
            }
            else if(tam==1000){
                leituraArquivos("vetorMilOrdenado.txt", vetorMil, 1000);
                resultBuscaB = buscaBinaria(vetorMil, 1000, valor);
            }
            else if(tam==10000){
                leituraArquivos("vetorDezMilOrdenado.txt", vetorDezMil, 10000);
                resultBuscaB = buscaBinaria(vetorDezMil, 10000, valor);
            }
            else if(tam==100000){
                leituraArquivos("vetorCemMilOrdenado.txt", vetorCemMil, 100000);
                resultBuscaB = buscaBinaria(vetorCemMil, 100000, valor);
            }
            else{
                printf("Tamanho invalido\n");
                system("pause"); system("cls");
                menu();
            }
            if(resultBuscaB!=(-1))
                printf("Valor %d encontrado na posicao %d\n",valor,resultBuscaB);
            else
                printf("Valor %d nao esta no vetor\n",valor);
            system("pause"); system("cls");
            menu();
            break;
        default:
            menu();
            break;
    }
}

/*Função para salvar nos arquivos txt*/
void salvarTXT(int v[], char nomeDoArquivo[], int tam){//vetor a ser gravado, nome arquivo, tamanho vetor
    /* Os arquivos são criados na pasta onde estiver salvo esse algoritmo */
    /* na hora de passar o nome do arquivo NÃO ESQUECER o .txt*/
    FILE *f = fopen(nomeDoArquivo, "wb"); //abre/cria um arquivo no modo de escrita binário
    if(f ==  NULL){
        printf("Erro ao gerar arquivos de texto :C\n");
        printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
        menu();
    }
    if(fwrite(v,sizeof(int),tam,f))//verifica se foi gravado no arquivo
        printf("Arquivo %s gerado com sucesso\n", nomeDoArquivo);
    fclose(f);
}

/* função para leitura dos arquivos*/
void leituraArquivos(char nomeDoArquivo[], int *refVet, int tam){
    int vetor[tam];//Vetor para onde os elementos do arquivo serão trazidos
    int i;
    FILE * arq = fopen(nomeDoArquivo, "rb");//abre o arquino no modo de leitura binário
    /*fread(endereço para onde vão as informações, tamanho de cada dado, quantidade de dados a ser lida, arquivo de onde pegar os dados*/
    fread(&vetor,sizeof(int),tam,arq);//passa os valores do arquivo para o vetor
    for(i=0; i<tam; i++)
        refVet[i]=vetor[i];
}

void gerarNumeros(){

    int i, x;
    int vetCem[100];
    int vetMil[1000];
    int vetDezMil[10000];
    int vetCemMil[100000];

    srand((unsigned)time(NULL)); //alimenta a função rand() com o tempo atual

    /* preenche o vetor de 100 posições  */
    for(i=0 ; i < 100 ; i++){
        x = rand() % 100000;// gera o número aleatório entre[0 a 100000] e guarda em x
        vetCem[i] = x; // guarda x no vetor de 100 elementos
    }
    salvarTXT(vetCem, "vetorCem.txt", 100);//salva no arquivo

    /* preenche o vetor de 1000 posições  */
    for(i=0 ; i < 1000 ; i++){
        x = rand() % 100000;// gera o número aleatório entre[0 a 100000] e guarda em x
        vetMil[i] = x; // guarda x no vetor de 1000 elementos
    }
    salvarTXT(vetMil, "vetorMil.txt", 1000);//salva no arquivo

    /* preenche o vetor de 10000 posições  */
    for(i=0 ; i < 10000 ; i++){
        x = rand() % 100000;// gera o número aleatório entre[0 a 100000] e guarda em x
        vetDezMil[i] = x; // guarda x no vetor de 10000 elementos
    }
    salvarTXT(vetDezMil, "vetorDezMil.txt", 10000);//salva no arquivo

    /* preenche o vetor de 100000 posições  */
    for(i=0 ; i < 100000 ; i++){
        x = rand() % 100000;// gera o número aleatório entre[0 a 100000] e guarda em x
        vetCemMil[i] = x; // guarda x no vetor de 100000 elementos
    }
    salvarTXT(vetCemMil, "vetorCemMil.txt", 100000);//salva no arquivo
}

int selectionSort(int *vetor, int tam){
    int i, j, eleito, menor, pos;
    double comparacoes=0, trocas=0;
    for(i=0; i<tam-1; i++){
        eleito = vetor[i];
        menor = vetor[i + 1];
        pos = i + 1;
        for(j=i+1; j<tam; j++){
            comparacoes++;
            if(vetor[j]<menor){
                menor = vetor[j];
                pos = j;
            }
        }
        if(menor < eleito){
            trocas++;
            vetor[i] = vetor[pos];
            vetor[pos] = eleito;
        }
    }
    printf("Tamanho: %d\n",tam);
    printf("Quant. de Comparacoes: %.0f\n",comparacoes);
    printf("Quant. de Trocas: %.0f\n",trocas);
}

int insertionSort(int *vetor, int tam){
    int i, j, valorAtual;
    double comparacoes=0, trocas=0;
    for(j=1; j<tam; j++){
        valorAtual = vetor[j];
        i = j-1;
        comparacoes++;
        while(i>=0 && vetor[i]>valorAtual){
            trocas++;
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = valorAtual;
    }
    printf("Tamanho: %d\n",tam);
    printf("Quant. de Comparacoes: %.0f\n",comparacoes);
    printf("Quant. de Trocas: %.0f\n",trocas);
}

int bubbleSort(int *vetor, int tam){
    int i, j, aux, k;
    double comparacoes=0, trocas=0;

    k = tam - 1 ;
    for(i=0; i<tam; i++){
        for(j=0; j<k; j++){
            comparacoes++;
            if(vetor[j]>vetor[j+1]){
                trocas++;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1]=aux;
            }
        }
        k--;
    }
    printf("Tamanho: %d\n",tam);
    printf("Quant. de Comparacoes: %.0f\n",comparacoes);
    printf("Quant. de Trocas: %.0f\n",trocas);
}

int heapSort(int *vetor, int tam){
    double comparacoes=0, trocas=0;
    void criaHeap(int *vet, int c, int f){
        int aux = vet[c];
        int j = c * 2 + 1;
        while(j<=f){
            if(j<f){
                comparacoes++;
                if(vet[j] < vet[j+1]){
                    j=j+1;
                }
            }
            comparacoes++;
            if(aux<vet[j]){
                trocas++;
                vet[c] = vet[j];
                c = j;
                j = 2*c+1;
            }else{
                j=f+1;
            }
        }
        vet[c] = aux;
    }

    int i, aux;
    for(i=(tam-1)/2; i>=0; i--){
        criaHeap(vetor, i, tam-1);
    }

    for(i=tam-1; i>=1; i--){
        trocas++;
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1);
    }
    printf("Tamanho: %d\n",tam);
    printf("Quant. de Comparacoes: %.0f\n",comparacoes);
    printf("Quant. de Trocas: %.0f\n",trocas);
}

int mergeSort(int *vetor, int inicio, int fim){
    int meio;
    void merge(int *vetor, int inicio, int meio, int fim){
        int *temp, p1, p2, tamanho, i, j ,k;
        int fim1 = 0, fim2 = 0;
        tamanho = fim - inicio+1;
        p1 = inicio;
        p2 = meio+1;
        temp = (int *)malloc(tamanho*sizeof(int));
        if(temp!=NULL){
            for(i=0; i<tamanho; i++){
                if(!fim1 && !fim2){
                    compMerge++;
                    if(vetor[p1]<vetor[p2])
                        temp[i]=vetor[p1++];
                    else
                        temp[i]=vetor[p2++];
                    if(p1>meio)
                        fim1=1;
                    if(p2>fim)
                        fim2=1;
                }else{
                    if(!fim1)
                        temp[i]=vetor[p1++];
                    else
                        temp[i]=vetor[p2++];
                }
            }
            for(j=0,k=inicio; j<tamanho; j++,k++)
                vetor[k]= temp[j];
        }
        free(temp);
    }
    if(inicio < fim){
        meio = (inicio+fim)/2;
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        merge(vetor,inicio,meio,fim);
    }
}

int quickSort(int *vetor, int inicio, int fim){
    int particiona(int *vetor, int inicio, int fim){
        int esq, dir, pivo, aux;
        esq = inicio;
        dir = fim;
        pivo = vetor[inicio];
        while(esq<dir){
            while(vetor[esq]<=pivo){
                esq++;
                compQuick++;
            }
            compQuick++;
            while(vetor[dir]>pivo){
                dir--;
                compQuick++;
            }
            compQuick++;
            if(esq<dir){
                trocaQuick++;
                aux = vetor[esq];
                vetor[esq] = vetor[dir];
                vetor[dir] = aux;
            }
        }

        vetor[inicio] = vetor[dir];
        vetor[dir] = pivo;
        return dir;
    }
    int pivo;
    if(fim>inicio){
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int radixSort(int *vetor, int tam){
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tam, sizeof(int));

    for(i=0; i<tam; i++){
        if(vetor[i] > maior)
    	    maior = vetor[i];
    }

    while(maior/exp > 0){
        int bucket[10] = { 0 };
    	for(i=0; i<tam; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for(i=1; i<10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i=tam - 1; i>=0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i=0; i<tam; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
    printf("Tamanho: %d\n",tam);
}

int buscaSequencial(int *vetor, int tam, int valor){
    double comparacoes = 0;
    int i;
    for(i=0; i<tam; i++){
        comparacoes++;
        if(valor==vetor[i]){
            printf("Tamanho: %d\n",tam);
            printf("Quant. de Comparacoes: %.0f\n",comparacoes);
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *vetor, int tam, int valor){
    double comparacoes = 0;
    int inicio = 0;
    int fim = tam-1;
    int meio;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        comparacoes++;
        if(valor == vetor[meio]){
            printf("Tamanho: %d\n",tam);
            printf("Quant. de Comparacoes: %.0f\n",comparacoes);
            return meio;
        }
        if(valor < vetor[meio])
            fim = meio-1;
        else
            inicio = meio+1;
    }
    return -1;
}

int main(){
    menu();
    return 0;
}
