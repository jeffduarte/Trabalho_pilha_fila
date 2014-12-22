#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#endif // FILA_H_INCLUDED

//funções

int inserirNF();
int inserirCF();
void deletarF();
void ordenarNF();
void ordenarCF();
void exibir_fila();
int buscarF();
int encherF();
void tamanho_Tfila();
void exibir_Tfila();
void zerar_fila();
void restaurarF();
void regravarF();


//Variáveis FILA

node *primeiro = NULL;
node *ultimo = NULL;
node *auxf = NULL;
node *atualf = NULL;
node *backupF = NULL;
node *fila_ultimo = NULL;

//Variáveis Globais fila

int tamanho_fila = 0;
int mesmafila = 0;
int aux, i;
char auxc;

//variaveis Fila

int inserirNF();
int inserirCF();
void deletarF();
void ordenarCF();
void ordenarNF();
int encherF();
void restaurarNF();
void restaurarCF();
void mesmo_no_f(char c);
void verifica_numero(node* destino);

//funções FILA



int inserirCF()
{
    CLEAR
    if (mesmafila == 1)
    {
        printf("Digite as informacoes: ");
        setbuf(stdin, NULL);
        fgets(primeiro->STRING,sizeof(primeiro->STRING), stdin);
        mesmafila = 0;
    }
    else if (primeiro == NULL)
        {
            primeiro = (node*)malloc(sizeof(node));
            if (primeiro == NULL)
            {
                printf("\n\nSem espaço na memoria\n");
                return -1;
            }
            primeiro->prox = NULL;
            primeiro->valor = 0;
            atualf = primeiro;
            strcpy(primeiro->STRING,"NULO");
            printf("\n\nDigite as informacoes: ");
            setbuf(stdin,NULL);
            fgets(primeiro->STRING,sizeof(primeiro->STRING),stdin);
            tamanho_fila++;
            fila_ultimo = primeiro;
            mesmo_no_f('v');
        }
    else
        {
            auxf = (node*)malloc(sizeof(node));
            if (auxf == NULL)
            {
                printf("\n\nSem espaço na memoria\n");
                getch();
                return -1;
            }
            auxf->valor = 0;
            strcpy(auxf->STRING,"NULO");
            printf("\n\nDigite as informacoes: ");
            setbuf(stdin,NULL);
            fgets(auxf->STRING,sizeof(auxf->STRING),stdin);
            auxf->prox = fila_ultimo;
            fila_ultimo = auxf;
            atualf = auxf;
            tamanho_fila++;
            mesmo_no_f('v');
        }

}


//FUNÇÃO INSERIR VALOR NUMÉRICO
int inserirNF()
{
    CLEAR
    if (mesmafila == 1)
    {
        verifica_numero(primeiro);
        mesmafila = 0;
    }
    else if (primeiro == NULL)
        {
            primeiro = (node*)malloc(sizeof(node));
            if (primeiro == NULL)
            {
                printf("Sem espaço na memoria\n");
                getch();
                return -1;
            }
            primeiro->prox = NULL;
            verifica_numero(primeiro);
            strcpy(primeiro->STRING,"NULO");
            tamanho_fila++;
            atualf = primeiro;
            fila_ultimo = primeiro;
            mesmo_no_f('s');
        }
    else
        {
            auxf = (node*)malloc(sizeof(node));
            if (auxf == NULL)
            {
                printf("Sem espaço na memoria\n");
                getch();
                return -1;
            }
            printf("\nDigite o valor: ");
            verifica_numero(auxf);
            auxf->prox = fila_ultimo;
            fila_ultimo = auxf;
            atualf = auxf;
            strcpy(fila_ultimo->STRING,"NULL");
            tamanho_fila++;
            mesmo_no_f('s');
        }
}



void deletarF()
{
    CLEAR
    if(primeiro == NULL)
    {
        printf("Nenhum valor armazenado.");
        getch();
    }
    else
    {
    printf("tem certeza que deseja deletar o 'primeiro'?\n's' para sim ou 'n' para nao: ");
    setbuf(stdin, NULL);
    scanf("%c%*c", &auxc);
    if (auxc == 's')
    {
        if (backup == NULL)
        {
            backup = (node*)malloc(sizeof(node));
            if (backup != NULL)
            {
                backup->prox = primeiro->prox;
                backup->valor = primeiro->valor;
                strcpy(backup->STRING,primeiro->STRING);
            }
            }
            else
            {
                backup->prox = primeiro->prox;
                backup->valor = primeiro->valor;
                strcpy(backup->STRING,primeiro->STRING);
            }
        printf("A estrutura com os valores %d e %s foi deletada com sucesso da fila.",primeiro->valor, primeiro->STRING);
        auxf = primeiro->prox;
        free(primeiro);
        primeiro = auxf;
        tamanho_fila--;
        getch();
    }
    }
}

void mesmo_no_f(char c)
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
            mesmafila = 1;
            inserirNF();
            break;
        }
        else if (auxc == 'n')
        {
            mesmafila = 0;
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
            mesmafila = 1;
            inserirCF();
            break;
        }
        else if (auxc == 'n')
        {
            mesmafila = 0;
            break;
        }
        else
            printf("\ncaractere invalido");
    }
}
}

void tamanho_Tfila()
{
    CLEAR
    printf("O tamanho atual da fila eh: %d", tamanho_fila);
    getch();
}

void exibir_Tfila()
{
    ICONTAGEM
    int i;
    auxf = primeiro;
    if (tamanho_fila == 0)
    {
        CLEAR
        printf("fila vazia!");
        getch();
    }
    else
    {

        CLEAR
        for(i=1;i<=tamanho_fila;i++)
        {
            printf("fila %d\nValor: %d\nCaracter: %s\n\n", i, auxf->valor, auxf->STRING);
            auxf = auxf->prox;
        }
        FCONTAGEM
        getch();
    }
}

void zerar_fila()
{
    CLEAR
    if (primeiro == NULL)
    {
        printf ("A fila ja esta vazia!");
        getch();
    }
    else
    {
        printf("Tem certeza que deseja zerar toda a fila? 's' para sim 'n' para nao: ");
        setbuf(stdin,NULL);
        scanf("%c%*c", &auxc);
        if (auxc == 's')
        {
            int i = 0;
            for (i=1;i<=tamanho_fila;i++)
            {
                auxf = primeiro->prox;
                free(primeiro);
                primeiro = auxf;
            }
            printf("A fila foi esvaziada!");
            tamanho_fila = 0;
            getch();
        }
    }

}

void restaurarF()
{
    CLEAR
    primeiro = backup;
    printf("A fila com o valor: %d e a informacao: %s foi restaurada com sucesso!", primeiro->valor,primeiro->STRING);
    tamanho_fila++;
    getch();
}
void regravarF()
{
    CLEAR
    if (primeiro == NULL)
    {
        printf("A fila esta vazia");
        getch();
    }
    else
    {
        mesmafila = 1;
        inserirCF();
        mesmafila = 1;
        inserirNF();
    }
}

int encherF()
{
    CLEAR
    int i = 0;
    printf("Digite quantos 'nodes' deseja criar: ");
    setbuf(stdin,NULL);
    scanf("%d%*c",&aux);
    tamanho_fila += aux;
    if(primeiro == NULL)
    {
        auxf = (node*)malloc(sizeof(node));
        if (auxf == NULL)
        {
            printf("Sem espaco na memoria");
            tamanho_fila -= aux;
            getch();
            return 0;
        }
        auxf->valor = i+tamanho_fila;
        strcpy(auxf->STRING,"REPLICA FILA");
        auxf->prox = NULL;
        fila_ultimo = auxf;
        primeiro = auxf;
        atualf = primeiro;
        aux--;
    }
        for (i=1;i<=(aux);i++)
        {
            auxf = (node*)malloc(sizeof(node));
            if (auxf == NULL)
            {
                printf("Sem mais espaco na memoria, apenas %d nodes foram criados", i);
                tamanho_fila-=aux;
                tamanho_fila+=(i-1);
                getch();
                return 0;
            }
            auxf->valor = i+tamanho_fila;
            strcpy(auxf->STRING,"REPLICA FILA");
            auxf->prox = NULL;
            atualf->prox = auxf;
            atualf = auxf;
            fila_ultimo = auxf;
        }
        printf("A fila foi preenchida");
        getch();
    }

    int buscarF()
    {
        CLEAR
        if (primeiro == NULL)
        {
            printf("Fila vazia");
            return 0;
        }
        printf ("Deseja procurar sobre valor ou informacao? valor 0, informacao 1: ");
        setbuf(stdin,NULL);
        scanf("%d%*c", &aux);
        if (aux == 0)
        {
            auxf = primeiro;
            printf("\nDigite o numero a ser buscado: ");
            setbuf(stdin,NULL);
            scanf("%d%*c", &aux);
            for (i = 1;i<=tamanho_fila;i++)
            {
                if (aux==auxf->valor)
                {
                    printf("O numero: %d se encontra no endereco: %p\n",auxf->valor,auxf);
                    getch();
                    return 0;
                }
                auxf = auxf->prox;
                if (auxf == NULL)
                {
                    printf("\nValor nao se encontra na fila");
                    getch();
                    return 0;
                }
            }
        }
        else if (aux == 1)
        {
            auxf = primeiro;
            printf("\nDigite o que busca: ");
            fgets(auxs,sizeof(auxs),stdin);
            while (1)
            {
                if ((strcmp(auxf->STRING,auxs) == 0))
                {
                    printf("\nValor encontrado na variavel de endereco %p",auxf);
                    getch();
                    return 0;
                }
                auxf = auxf->prox;
                if (auxf->prox == NULL)
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
