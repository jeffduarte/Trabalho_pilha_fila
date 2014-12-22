#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PFJ.h"
#include <string.h>

int main()
{
    int menu = 1, menu1 = 1;

    while (menu1 != 3)
    {
        CLEAR
        printf(" --MENU--\n1 - Pilha\n2 - Fila\n3 - Sair\nopcao: ");
        setbuf(stdin,NULL);
        scanf("%d%*c", &menu1);
        menu = 1;
        switch(menu1)
        {
            case 1:
                while (menu)
                {
                    CLEAR
                    printf(" --MENU PILHA--\n1 - Inserir valor\n2 - Inserir caracteres\n3 - Imprimir ultimo\n4 - Deletar\n5 - Tamanho da Pilha\n6 - Exibir pilha\n7 - Esvaziar pilha\n8 - Restaurar ultima\n9 - Regravar\n10 - Encher\n11 - Busca\n12 - Menu principal\n");
                    scanf("%d", &aux);
                    switch (aux)
                    {
                        case 1:
                            inserirNP();
                            break;
                        case 2:
                            inserirCP();
                            break;
                        case 3:
                            exibir_pilha();
                            break;
                        case 4:
                            deletarP();
                            break;
                        case 5:
                            tamanho_Tpilha();
                            break;
                        case 6:
                            exibir_Tpilha();
                            break;
                        case 7:
                            zerar_pilha();
                            break;
                        case 8:
                            restaurarP();
                            break;
                        case 9:
                            regravarP();
                            break;
                        case 10:
                            encherP();
                            break;
                        case 11:
                            buscarP();
                            break;
                        case 12:
                            menu = 0;
                            break;

                    }
                }
                break;
                case 2:
                    while (menu)
                    {
                        CLEAR
                        printf(" --MENU FILA--\n1 - Inserir valor\n2 - Inserir caracteres\n3 - Imprimir primeiro\n4 - Deletar\n5 - Tamanho da Fila\n6 - Exibir fila\n7 - Esvaziar fila\n8 - Restaurar ultima\n9 - Regravar\n10 - Encher\n11 - Busca\n12 - Menu principal\n");
                        scanf("%d", &aux);
                        switch (aux)
                        {
                            case 1:
                                inserirNF();
                                break;
                            case 2:
                                inserirCF();
                                break;
                            case 3:
                                exibir_Tfila();
                                break;
                            case 4:
                                deletarF();
                                break;
                            case 5:
                                tamanho_Tfila();
                                break;
                            case 6:
                                exibir_Tfila();
                                break;
                            case 7:
                                zerar_fila();
                                break;
                            case 8:
                                restaurarF();
                                break;
                            case 9:
                                regravarF();
                                break;
                            case 10:
                                encherF();
                                break;
                            case 11:
                                buscarF();
                                break;
                            case 12:
                                menu = 0;
                                break;

                        }
                    }
                    break;
                case 3:
                    menu1 = 3;
                    break;
                default:
                    printf("Opcao invalida");
                    getch();

        }

    }
    return 0;
}


