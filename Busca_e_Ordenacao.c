#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/* Declaração das funções */
void menu();
void gerarNumeros();
void salvarTXT(int v[], char nomeDoArquivo[], int tam);
void leituraArquivos(char nomeDoArquivo[], int tam);
int selectionSort();
int insertionSort();
int bubbleSort();
int heapSort();
int mergeSort();
int quickSort();
int buscaSequencial();
int buscaBinaria();


void menu(){
    int op;
    printf("Escolha uma opcao para busca e ordenacao:\n");
    printf("0 - Sair do algoritmo\n");
    printf("1 - Gerar sequencia de numeros para ordenacao e busca.\n");
    printf("2 - Ordenar utilizando selection sort.\n");
    printf("3 - Ordenar utilizando insertion sort.\n");
    printf("4 - Ordenar utilizando bubble sort.\n");
    printf("5 - Ordenar utilizando heap sort.\n");
    printf("6 - Ordenar utilizando merge sort.\n");
    printf("7 - Ordenar utilizando quick sort.\n");
    printf("8 - Fazer busca utilizando busca sequencial.\n");
    printf("9 - Fazer busca utilizando busca binaria.\n");
    scanf("%d",&op);

    switch(op){
        case 0:
            exit(0);
            break;
        case 1 :
            gerarNumeros();
            break;
        case 2:
            //selectionSort();
            break;
        case 3:
            //insertionSort();
            break;
        case 4:
            //bubbleSort();
            break;
        case 5:
            //heapSort();
            break;
        case 6:
            //mergeSort();
            break;
        case 7:
            //quickSort();
            break;
        case 8:
            //buscaSequencial();
            break;
        case 9:
            //buscaBinaria();
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
void leituraArquivos(char nomeDoArquivo[], int tam){
    int vetor[tam];//Vetor para onde os elementos do arquivo seram trazidos
    int i;
    FILE * arq = fopen(nomeDoArquivo, "rb");//abre o arquino no modo de leitura binário
    /*fread(endereço para onde vão as informações, tamanho de cada dado, quantidade de dados a ser lida, arquivo de onde pegar os dados*/
    fread(&vetor,sizeof(int),tam,arq);//passa os valores do arquivo para o vetor
    for(i=0; i<tam; i++)
        printf("[%d, ",vetor[i],"]\n");
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

    /* EXEMPLO DA CHAMADA DA FUNÇÃO DE LEITURA DOS ARQUIVOS*/
    leituraArquivos("vetorCem.txt", 100);//Passa o nome do arquivo .txt e a quantidade de numeros nele

    menu();
}

int main(){
    menu();
    return 0;
}
