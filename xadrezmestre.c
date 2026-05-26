#include <stdio.h>

// Funcao da Torre: move X casas para a direita
void moverTorre(int casas) {
    // Caso base: se nao tem mais casas, para
    if (casas == 0) return;
    printf("Direita\n");
    // Chama ela mesma com uma casa a menos
    moverTorre(casas - 1);
}

// Funcao do Bispo: move X casas na diagonal
void moverBispo(int casas) {
    // Caso base: se nao tem mais casas, para
    if (casas == 0) return;
    printf("Cima\n");
    printf("Direita\n");
    // Chama ela mesma com uma casa a menos
    moverBispo(casas - 1);
}

// Funcao da Rainha: move X casas para a esquerda
void moverRainha(int casas) {
    // Caso base: se nao tem mais casas, para
    if (casas == 0) return;
    printf("Esquerda\n");
    // Chama ela mesma com uma casa a menos
    moverRainha(casas - 1);
}

int main() {

    // =========================================
    // Variaveis: guardam quantas casas cada 
    // peca vai se mover
    // =========================================
    int casasTorre  = 5;
    int casasBispo  = 5;
    int casasRainha = 8;
    int movCavalo   = 5;

    // Variaveis de controle dos loops
    int i; // loop externo
    int j; // loop interno (usado no cavalo e bispo)


    // =========================================
    // TORRE
    // =========================================

    // Versao original com FOR
    printf("=== Torre (for) ===\n");
    for (i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // Versao nova com recursividade
    // (a funcao fica chamando ela mesma
    //  ate chegar em zero)
    printf("\n=== Torre (recursividade) ===\n");
    moverTorre(casasTorre);


    // =========================================
    // BISPO
    // =========================================

    // Versao original com DO-WHILE
    printf("\n=== Bispo (do-while) ===\n");
    i = 1;
    do {
        printf("Cima\n");
        printf("Direita\n");
        i++;
    } while (i <= casasBispo);

    // Versao nova com recursividade + loops aninhados
    // (loop aninhado = um loop dentro do outro)
    printf("\n=== Bispo (recursividade + loops aninhados) ===\n");
    for (i = 1; i <= casasBispo; i++) {       // loop externo: conta as casas verticais
        for (j = 1; j <= 1; j++) {            // loop interno: conta as casas horizontais
            printf("Cima\n");
            printf("Direita\n");
        }
    }


    // =========================================
    // RAINHA
    // =========================================

    // Versao original com WHILE
    printf("\n=== Rainha (while) ===\n");
    i = 1;
    while (i <= casasRainha) {
        printf("Esquerda\n");
        i++;
    }

    // Versao nova com recursividade
    printf("\n=== Rainha (recursividade) ===\n");
    moverRainha(casasRainha);


    // =========================================
    // CAVALO
    // =========================================

    // Versao original com loops aninhados simples
    printf("\n=== Cavalo (loops aninhados) ===\n");
    for (i = 1; i <= movCavalo; i++) {
        printf("Movimento %d:\n", i);
        for (j = 1; j <= 2; j++) {   // repete 2 vezes: duas casas para cima
            printf("  Cima\n");
        }
        printf("  Direita\n");        // uma casa para a direita
    }

    // Versao nova com loops complexos, break e continue
    // break    = sai do loop na hora
    // continue = pula para a proxima repeticao do loop
    printf("\n=== Cavalo (loops complexos + break/continue) ===\n");
    for (i = 1; i <= movCavalo; i++) {

        // 'continue' pula uma iteracao especifica
        // (aqui nunca acontece pois i comeca em 1,
        //  mas mostra como o continue funciona)
        if (i == 0) continue;

        printf("Movimento %d:\n", i);

        for (j = 1; j <= 3; j++) {
            // 'break' sai do loop quando j chega em 3
            // assim o loop so executa para j=1 e j=2
            if (j == 3) break;
            printf("  Cima\n");
        }

        printf("  Direita\n");

        // 'break' encerra o loop externo ao fim
        // do ultimo movimento
        if (i == movCavalo) break;
    }

    return 0;
}