#include "func.h"


int Insertionsort_ponteiro(int v[],int n)
{
    int i,j,temp;
for(i=1;i<n;i++)
    {
        temp=*(v+i);
        j=i-1;
        while(temp<*(v+j)&&j>=0)
        {
            *(v+(j+1))=*(v+j);
            j--;
        }
        *(v+(j+1))=temp;
    }
    return 0;
}




void Heapsort(int v[], int n) {

   int i = n / 2, pai, filho, t;

   for (;;) {
      if (i > 0) {
          i--;
          t = v[i];
          comparacoes++;
      } else {
          n--;
          if (n == 0) return;
          t = v[n];
          trocas++;
          v[n] = v[0];
      }

      pai = i;

      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i * 2 + 1;

      while (filho < n) {

         // Se o filho da esquerda for menor do que o filho da direita,
         // então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho]))
              filho++;
          if (v[filho] > t) {
             v[pai] = v[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      v[pai] = t;
   }
}


/*A diferença entre o primeiro exemplo é o laço for mais interno.

Ele não mais compara n - 1 e sim n - k, ou seja, ele é mais econômico e reflete com fidelidade o algoritmo Bubble Sort.*/
void Bubblesort (int v[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - k; j++) {
                comparacoes++;
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j]     = v[j + 1];
                v[j + 1] = aux;
                trocas++;
            }
        }
    }
}


/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void Mergesort(int v[], int n) {
  int *c = malloc(sizeof(int) * n);
  Sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void Sort(int v[], int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  Sort(v, c, i, m);
  Sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  Merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void Merge(int v[], int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++)
    c[z] = v[z];
  trocas++;

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */
     comparacoes++;
    if (c[iv] < c[ic]){
        v[z++] = c[iv++];
        trocas++;
    }
    else /* if (c[iv] > c[ic]) */ v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}


void Insercao (int v[], int n )
{
    int i,j;
    int aux;
    for (i = 1; i < n; i++)
    {
        aux = v[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux < v[j] ) )
        {
            comparacoes++;
            trocas++;
            v[j + 1] = v[j];
            j--;
        }
        trocas++;
        v[j + 1] = aux;
    }
}

void Selecao (int v[], int n)
{
    int i, j, Min;
    int aux;
    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1 ; j < n; j++)
        {
            comparacoes++;
            if ( v[j] < v[Min])
            {
                Min = j;
            }
        }
        trocas++;
        aux = v[Min];
        v[Min] = v[i];
        v[i] = aux;
    }
}

void Shell(int v[], int n)
{
    int i, j, value;
    int gap = 1;

    do
    {
        gap = 3*gap+1;
    }
    while(gap < n);

    do
    {
        gap /= 3;
        for(i = gap; i < n; i++)
        {
            value = v[i];
            j = i - gap;

            while (j >= 0 && value < v[j])
            {
                comparacoes++;
                trocas++;
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j + gap] = value;
        }
    }
    while(gap > 1);
}

void Quick(int v[10], int inicio, int fim)
{
    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = v[meio];

    do
    {
        while (v[i] < pivo)
        {
            comparacoes++;
            i = i + 1;
        }
        while (v[j] > pivo)
        {
            comparacoes++;
            j = j - 1;
        }

        comparacoes++;
        if(i <= j)
        {
            trocas++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }
    while(j > i);

    if(inicio < j)
        Quick(v, inicio, j);
    if(i < fim)
        Quick(v, i, fim);
}

void Imprimir(int v[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d,",v[i]);
}

void LimparTela()
{
    system("pause");
    system("cls");
}

int LerInteiro(char frase[])
{
    int num;
    printf("%s",frase);
    fflush(stdin);
    scanf("%d",&num);
    printf("\n");
    return num;
}

int CarregarArquivo(Vetor *vetor)
{
    int n, tipo, i;
    char nome[16];
    FILE *arquivo = NULL;

    n = LerInteiro("INFORME O TAMANHO DO ARQUIVO: ");
    tipo = LerInteiro("INFORME O TIPO DO ARQUIVO\n\n1. CRESCENTE\n2. DESCRESCENTE\n3. ALEATORIO\n\nOPCAO: ");

    sprintf(nome,"%d_%d.dat",tipo,n);

    arquivo = fopen(nome,"r"); // abre o arquivo no modo de leitura

    if(arquivo == NULL)
        return 0; // retorna 0 indicando que nao achou o arquivo...

    vetor->n = n; // atribui tamanho ao vetor
    vetor->v = (int*)malloc(sizeof(int) * n); // aloca o vetor

    for(i=0; i<n; i++)
        fscanf(arquivo,"%d,",&vetor->v[i]);

    return 1; // retorna status de sucesso
}

int CriarArquivo(int tipo,int n)
{
    int i;
    char nome[16];
    FILE *arquivo = NULL;

    sprintf(nome,"%d_%d.dat",tipo,n);
    arquivo = fopen(nome,"w");

    if(arquivo == NULL)
        return 0; // caso nao consiga abrir o arquivo

    for(i=0; i<n; i++)
    {
        if(tipo == 1) // caso seja tipo crescente
            fprintf(arquivo,"%d,",(i+1));
        else if(tipo == 2) // caso seja tipo decrescente
            fprintf(arquivo,"%d,",(n-i));
        else if(tipo == 3) // caso seja tipo aleatorio
            fprintf(arquivo,"%d,",( (rand() % n)+1) );
        else
            return 0;
    }

    fclose(arquivo);
    return 1;
}

void LiberarVetor(Vetor *vetor)
{
    if(vetor->v != NULL)
    {
        free(vetor->v);
        vetor->v = NULL;
    }
    vetor->n = 0;
}

void ResetarContadores()
{
    trocas = 0;
    comparacoes = 0;
    tempoGasto = 0;
}

void ImprimirRelatorioOrdenacao(char metodo[], int n)
{
    printf("METODO: %s\nTAMANHO: %d\n",metodo,n);
    printf("TROCAS: %lu\n",trocas);
    printf("COMPARACOES: %lu\n",comparacoes);
    printf("TEMPO: %ld ms\n",tempoGasto);
}

void MenuAnaliseComparativa()
{
    int opcao;
    Vetor vetor;

    do
    {
        ResetarContadores();
        LimparTela();
        printf("================= MENU CONSTRUCAO DE ARQUIVOS =================\n\n");
        printf("[1] ORDENAR UTILIZANDO SELECTION-SORT\n");
        printf("[2] ORDENAR UTILIZANDO INSERTION-SORT\n");
        printf("[3] ORDENAR UTILIZANDO BUBBLE-SORT\n");
        printf("[4] ORDENAR UTILIZANDO SHELL-SORT\n");
        printf("[5] ORDENAR UTILIZANDO QUICK-SORT\n");
        printf("[6] ORDENAR UTILIZANDO MERGE-SORT\n");
        printf("[7] ORDENAR UTILIZANDO HEAP-SORT\n");
        printf("[8] ORDENAR UTILIZANDO INSERTION-SORT-DINAMICO\n");
        printf("[9] VOLTAR AO MENU PRINCIPAL\n\n");
        printf("OPCAO: ");
        fflush(stdin);
        scanf("%d",&opcao);
        printf("\n");

        switch(opcao)
        {
        case 1:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();
                Selecao(vetor.v,vetor.n);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("SELECTION-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
        case 2:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();
                Insercao(vetor.v,vetor.n);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("INSERTION-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
        case 3:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();
                Bubblesort(vetor.v,vetor.n);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("BUBBLE-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
        case 4:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();
                Shell(vetor.v,vetor.n-1);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("SHELL-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
            case 5:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();


                Quick(vetor.v,0,vetor.n-1);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("QUICK-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;

            case 6:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();


                Mergesort(vetor.v,vetor.n-1);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("MERGE-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
            case 7:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();


                Insertionsort_ponteiro(vetor.v,vetor.n-1);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao(" INSERTION-SORT-DINAMICO",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
            case 8:
            if(CarregarArquivo(&vetor))
            {
                tempoGasto = clock();


                Heapsort(vetor.v,vetor.n-1);
                tempoGasto = clock() - tempoGasto;
                ImprimirRelatorioOrdenacao("HEAP-SORT",vetor.n);
                //Imprimir(vetor.v,vetor.n);
                LiberarVetor(&vetor);
            }
            else
                printf("ERRO: ARQUIVO NAO ENCONTRADO.\n");
            break;
        case 9:
            opcao = -1;
            break;
        default:
            printf("ERRO: OPCAO INVALIDA.\n");
            break;
        }
        printf("\n");
    }
    while(opcao != -1);
}

void MenuConstrucaoArquivos()
{
    int opcao,n;

    do
    {
        LimparTela();
        printf("================= MENU CONSTRUCAO DE ARQUIVOS =================\n\n");
        printf("[1] CRIAR ARQUIVO EM ORDEM CRESCENTE\n");
        printf("[2] CRIAR ARQUIVO EM ORDEM DECRESCENTE\n");
        printf("[3] CRIAR ARQUIVO EM ORDEM ALEATORIA\n");
        printf("[4] VOLTAR AO MENU PRINCIPAL\n\n");
        printf("OPCAO: ");
        fflush(stdin);
        scanf("%d",&opcao);
        printf("\n");

        if(opcao >= 1 && opcao <= 3)
            n = LerInteiro("INFORME O TAMANHO DO ARQUIVO: ");

        if(n <= 0 && opcao >= 1 && opcao <= 3)
            opcao = 99; // verifica se o usuario digitou um tamanho valido,
        // caso nao seja valido, entre em uma opcao invalida no switch

        switch(opcao)
        {
        case 1:
            if(CriarArquivo(1,n))
                printf("ARQUIVO CRIADO COM SUCESSO!\n");
            else
                printf("ERRO: FALHA AO CRIAR ARQUIVO.\n");
            break;
        case 2:
            if(CriarArquivo(2,n))
                printf("ARQUIVO CRIADO COM SUCESSO!\n");
            else
                printf("ERRO: FALHA AO CRIAR ARQUIVO.\n");
            break;
        case 3:
            if(CriarArquivo(3,n))
                printf("ARQUIVO CRIADO COM SUCESSO!\n");
            else
                printf("ERRO: FALHA AO CRIAR ARQUIVO\n");
            break;
        case 4:
            opcao = -1;
            break;
        default:
            printf("ERRO: OPCAO INVALIDA.\n");
            break;
        }

    }
    while(opcao != -1);
}

void MenuPrincipal()
{
    int opcao;

    do
    {
        printf("================= MENU PRINCIPAL =================\n\n");
        printf("[1] MENU CONSTRUCAO DE ARQUIVOS\n");
        printf("[2] ANALISE COMPARATIVA\n");
        printf("[3] SAIR\n\n");
        printf("OPCAO: ");
        fflush(stdin);
        scanf("%d",&opcao);
        printf("\n");

        switch(opcao)
        {
        case 1:
            MenuConstrucaoArquivos();
            break;
        case 2:
            MenuAnaliseComparativa();
            break;
        case 3:
            opcao = -1;
            printf("PROGRAMA FINALIZADO!\n");
            break;
        default:
            printf("ERRO: OPCAO INVALIDA.\n");
            break;
        }

        LimparTela();

    }
    while(opcao != -1);
}
