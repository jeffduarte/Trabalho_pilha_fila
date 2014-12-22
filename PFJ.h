#ifndef PFJ_H_INCLUDED
#define PFJ_H_INCLUDED
#endif
#ifdef LINUX
#define CLEAR system("clear");
#define ICONTAGEM struct timeval inicio, final;int tmili;gettimeofday(&inicio, NULL);
#define FCONTAGEM gettimeofday(&final, NULL);tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);printf("tempo decorrido: %d\n", tmili);
#elif defined(WIN32)
#define CLEAR system("cls");
#define ICONTAGEM     int inicio, final, tmili;inicio = GetTickCount();
#define FCONTAGEM         final = GetTickCount();tmili = final - inicio;printf("tempo decorrido: %.2f segundos\n", (float)tmili/1000);
#endif
#include <time.h>
#include <windows.h>
#include "pilha.h"
#include "fila.h"

void verifica_numero(node* destino);
//FUNÇÃO INSERIR STRING




void verifica_numero(node* destino)
{
        CLEAR
        printf("Digite o valor: ");
        for(;!scanf("%d*c", &destino->valor);)
        {
            setbuf(stdin, NULL);
            printf("\nEntrada invalida\n");
            printf("Digite o valor: ");
        }
}
