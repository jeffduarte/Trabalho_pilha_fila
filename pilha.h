#ifndef node_H_INCLUDED
#define node_H_INCLUDED
#endif // node_H_INCLUDED
#ifdef LINUX
#define CLEAR system("clear");
#elif defined(WIN32)
#define CLEAR system("cls");
#endif

typedef struct node
{
    char STRING[300];
    int valor;
    struct node* prox;
}node,*Tnode;

//funções

int inserirNP();
int inserirCP();
void deletarP();
void ordenarNP();
void ordenarCP();
void exibir_pilha();
int encherP();
void tamanho_Tpilha();
void exibir_Tpilha();
void zerar_pilha();
void restaurarP();
void regravarP();
int buscarP();

//Variáveis Pilha

node *topo = NULL;
node *proxp = NULL;
node *auxp = NULL;
node *fundo = NULL;
node *atual = NULL;
node *backup = NULL;
int tamanho_pilha = 0;
int mesmapilha = 0;
char auxc = 's';
int aux, i;
char auxc, auxs[300];



exibir_pilha()
{
    CLEAR
    if(topo == NULL)
    {
        printf("Nenhum valor armazenado.");
        getch();
    }
    else
    {
    printf("\nvalor: %d\nstring: %s", topo->valor, topo->STRING);
    getch();
    }
}

int inserirCP()
{
    CLEAR
    if (mesmapilha == 1)
    {
        printf("Digite as informacoes: ");
        setbuf(stdin, NULL);
        fgets(topo->STRING,sizeof(topo->STRING), stdin);
        mesmapilha = 0;
    }
    else if (topo == NULL)
        {
            topo = (node*)malloc(sizeof(node));
            if (topo == NULL)
            {
                printf("\n\nSem espaço na memoria\n");
                return -1;
            }
            topo->prox = NULL;
            topo->valor = 0;
            strcpy(topo->STRING,"NULO");
            printf("\n\nDigite as informacoes: ");
            setbuf(stdin,NULL);
            fgets(topo->STRING,sizeof(topo->STRING),stdin);
            tamanho_pilha++;
            mesmanodef('v');
        }
    else
        {
            auxp = (node*)malloc(sizeof(node));
            if (auxp == NULL)
            {
                printf("\n\nSem espaço na memoria\n");
                getch();
                return -1;
            }
            auxp->valor = 0;
            strcpy(auxp->STRING,"NULO");
            printf("\n\nDigite as informacoes: ");
            setbuf(stdin,NULL);
            fgets(auxp->STRING,sizeof(auxp->STRING),stdin);
            auxp->prox = topo;
            topo = auxp;
            tamanho_pilha++;
            mesmanodef('v');
        }

}


//FUNÇÃO INSERIR VALOR NUMÉRICO
int inserirNP()
{
    CLEAR
    if (mesmapilha == 1)
    {
        verifica_numero(topo);
        mesmapilha = 0;
    }
    else if (topo == NULL)
        {
            topo = (node*)malloc(sizeof(node));
            if (topo == NULL)
            {
                printf("Sem espaço na memoria\n");
                getch();
                return -1;
            }
            topo->prox = NULL;
            verifica_numero(topo);
            strcpy(topo->STRING,"NULO");
            tamanho_pilha++;
            mesmanodef('s');
        }
    else
        {
            auxp = (node*)malloc(sizeof(node));
            if (auxp == NULL)
            {
                printf("Sem espaço na memoria\n");
                getch();
                return -1;
            }
            printf("\nDigite o valor: ");
            verifica_numero(auxp);
            auxp->prox = topo;
            topo = auxp;
            strcpy(topo->STRING,"NULL");
            tamanho_pilha++;
            mesmanodef('s');
        }
}

void deletarP()
{
    CLEAR
    if(topo == NULL)
    {
        printf("Nenhum valor armazenado.");
        getch();
    }
    else
    {
    printf("tem certeza que deseja deletar o 'TOPO'?\n's' para sim ou 'n' para nao: ");
    setbuf(stdin, NULL);
    scanf("%c%*c", &auxc);
    if (auxc == 's')
    {
        if (backup == NULL)
        {
            backup = (node*)malloc(sizeof(node));
            if (backup != NULL)
            {
                backup->prox = topo->prox;
                backup->valor = topo->valor;
                strcpy(backup->STRING,topo->STRING);
            }
            }
            else
            {
                backup->prox = topo->prox;
                backup->valor = topo->valor;
                strcpy(backup->STRING,topo->STRING);
            }
        printf("A estrutura com os valores %d e %s foi deletada com sucesso da pilha.",topo->valor, topo->STRING);
        auxp = topo->prox;
        free(topo);
        topo = auxp;
        tamanho_pilha--;
        getch();
    }
    }
}

void mesmanodef(char c)
{
if (c == 'v')
{
    CLEAR
    while (1)
    {
        CLEAR
        printf("\Deseja gravar um inteiro nessa mesma node?\nDigite 's' para sim ou 'n' para nao: ");
        setbuf(stdin, NULL);
        auxc = getchar();
        if (auxc == 's')
        {
            mesmapilha = 1;
            inserirNP();
            break;
        }
        else if (auxc == 'n')
        {
            mesmapilha = 0;
            break;
        }
        else
            printf("\ncaractere invalido");
    }

}
else
{
    CLEAR
    while (1)
    {
        printf("Deseja gravar uma string nessa mesma node?\nDigite 's' para sim ou 'n' para nao: ");
        setbuf(stdin, NULL);
        auxc = getchar();
        fflush(stdin);
        if (auxc == 's')
        {
            mesmapilha = 1;
            inserirCP();
            break;
        }
        else if (auxc == 'n')
        {
            mesmapilha = 0;
            break;
        }
        else
            printf("\ncaractere invalido");
    }
}
}

void tamanho_Tpilha()
{
    CLEAR
    printf("O tamanho atual da pilha eh: %d", tamanho_pilha);
    getch();
}

void exibir_Tpilha()
{
    ICONTAGEM
    int i;
    auxp = topo;
    if (tamanho_pilha == 0)
    {
        CLEAR
        printf("Pilha vazia!");
        getch();
    }
    else
    {
        CLEAR
        for(i=tamanho_pilha;i>=1;i--)
        {
            printf("Pilha %d\nValor: %d\nCaracter: %s\n\n", i, auxp->valor, auxp->STRING);
            auxp = auxp->prox;
        }
        FCONTAGEM
        getch();
    }
}

void zerar_pilha()
{
    CLEAR
    if (topo == NULL)
    {
        printf ("A pilha ja esta vazia!");
        getch();
    }
    else
    {
        printf("Tem certeza que deseja zerar toda a pilha? 's' para sim 'n' para nao: ");
        setbuf(stdin,NULL);
        scanf("%c%*c", &auxc);
        if (auxc == 's')
        {
            int i = 0;
            for (i=1;i<=tamanho_pilha;i++)
            {
                auxp = topo->prox;
                free(topo);
                topo = auxp;
            }
            printf("A pilha foi esvaziada!");
            tamanho_pilha = 0;
            getch();
        }
    }

}

void restaurarP()
{
    CLEAR
    topo = backup;
    printf("A pilha com o valor: %d e a informacao: %s foi restaurada com sucesso!", topo->valor,topo->STRING);
    tamanho_pilha++;
    getch();
}
void regravarP()
{
    CLEAR
    if (topo == NULL)
    {
        printf("A pilha esta vazia");
        getch();
    }
    else
    {
        mesmapilha = 1;
        inserirCP();
        mesmapilha = 1;
        inserirNP();
    }
}

int encherP()
{
    CLEAR
    int i = 0;
    printf("Digite quantos 'nodes' deseja criar: ");
    setbuf(stdin,NULL);
    scanf("%d%*c",&aux);
    tamanho_pilha += aux;
    if(topo == NULL)
    {
        auxp = (node*)malloc(sizeof(node));
        if (auxp == NULL)
        {
            printf("Sem espaco na memoria");
            tamanho_pilha -= aux;
            getch();
            return 0;
        }
        auxp->valor = i+tamanho_pilha;
        strcpy(auxp->STRING,"REPLICA");
        auxp->prox = NULL;
        topo = auxp;
        aux--;
    }
        for (i=1;i<=(aux);i++)
        {
            auxp = (node*)malloc(sizeof(node));
            if (auxp == NULL)
            {
                printf("Sem mais espaco na memoria, apenas %d nodes foram criados", i);
                tamanho_pilha-=aux;
                tamanho_pilha+=(i-1);
                getch();
                return 0;
            }
            auxp->valor = i+tamanho_pilha;
            strcpy(auxp->STRING,"REPLICA");
            auxp->prox = topo;
            topo = auxp;
        }
        printf("A pilha foi preenchida");
        getch();
    }

    int buscarP()
    {
        CLEAR
        if (topo == NULL)
        {
            printf("Lista vazia");
            return 0;
        }
        printf ("Deseja procurar sobre valor ou informacao? valor 0, informacao 1: ");
        setbuf(stdin,NULL);
        scanf("%d%*c", &aux);
        if (aux == 0)
        {
            auxp = topo;
            printf("\nDigite o numero a ser buscado: ");
            setbuf(stdin,NULL);
            scanf("%d%*c", &aux);
            for (i = 1;i<=tamanho_pilha;i++)
            {
                if (aux==auxp->valor)
                {
                    printf("O numero: %d se encontra no endereco: %p\n",auxp->valor,auxp);
                    getch();
                    return 0;
                }
                auxp = auxp->prox;
                if (auxp == NULL)
                {
                    printf("\nValor nao se encontra na pilha");
                    getch();
                    return 0;
                }
            }
        }
        else if (aux == 1)
        {
            auxp = topo;
            printf("\nDigite o que busca: ");
            fgets(auxs,sizeof(auxs),stdin);
            while (1)
            {
                if ((strcmp(auxp->STRING,auxs) == 0))
                {
                    printf("\nValor encontrado na variavel de endereco %p",auxp);
                    getch();
                    return 0;
                }
                auxp = auxp->prox;
                if (auxp->prox == NULL)
                {
                    printf("\nValor nao localizado!");
                    getch();
                    return 0;
                }

            }

        }
        else
        {
            printf("Opcao invalida!");
            getch();
            return 0;
        }

    }
