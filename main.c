#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
    srand((unsigned)time(NULL)); // ALIMENTA O GERADOR DE NUMEROS ALEATORIO COM O TEMPO DO RELOGIO DO COMPUTADOR PARA
                                 // SEMPRE GERAR NUMEROS ALEATORIOS DIFERENTES
    MenuPrincipal(); // CHAMADA DO MENU PRINCIPAL
    return 0;
}
