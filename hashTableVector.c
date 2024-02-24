#include "mylib.h"

void    initializeTable(int *t) {
    for (size_t i = 0; i < TOP; i++) {
        t[i] = 0;
    }
}

void    insert(int *t, int valor) {
    int id = hashFunction(valor);
    printf("\t%i foi inserido na posição #%i", valor, id);
    while (t[id] != 0) {
        id = hashFunction(id + 1);
    }
    t[id] = valor;
}

int     search(int *t, int chave) {
    int id = hashFunction(chave);
    while (t[id] != 0) {
        if (t[id] == chave) 
            return t[id];
        else
            id = hashFunction(id + 1);
    }
    return 0;
}

int     searchByIndex(int *t, int chave) {
    if (chave >= 0 && chave <= 30) {
        int id = hashFunction(chave);
        while (t[id] != 0) {
            if (id == chave)
                return t[id];
            else
                id = hashFunction(id + 1);
        }
    }
    return -1;
}

int     printTable(int *t) {
    for (size_t i = 0; i < TOP; i++) {
        if (i <= 9)
            printf("0%i => %i\n", i, t[i]);
        else
            printf("%i => %i\n", i, t[i]);
    }    
}

void    randomTable(int *t) {
    for (size_t i = 0; i < TOP; i++) {
        t[i] = rand();
    }
}

void     randomValue(int *t) {
    int seed = rand() % (TOP + 1 - BOT) + BOT;
    int valor = rand();
    printf("\t%i foi inserido na posição #%i\n", valor, seed);
    while (t[seed] != 0)
        seed = hashFunction(seed + 1);
    t[seed] = valor;
}

int     findIndex(int *t, int chave) {
    int id = hashFunction(chave);
    return id;
}

int     main() {
    int table[TOP], valor, res, option, chave;
    initializeTable(table);
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar por valor\n\t3 - Buscar por posição\n\t4 - Imprimir\n\t5 - Tabela aleatória\n\t6 - Inserir valor aleatório\n\t7 - Apagar tabela\n");
        scanf("%i", &option);
        printf("\n");

        switch (option) {
        case 0:
            break;
        case 1:
            printf("\tInsira uma chave: ");
            scanf("%i", &chave);
            insert(table, chave);
            break;
        case 2:
            printf("\tDigite o valor que deseja buscar: ");
            scanf("%i", &valor);
            res = search(table, valor);
            if (res)
                printf("\tValor %i encontrado na posição #%i", res, findIndex(table, valor));
            else
                printf("\tValor não encontrado.\n");
            break;
        case 3:
            printf("\tDigite a posição que deseja consultar: ");
            scanf("%i", &valor);
            res = searchByIndex(table, valor);
            if (res != -1)
                printf("\tValor encontrado: %d", res);
            else if (valor < BOT || valor > TOP)
                printf("\tPosição fora dos limites do vetor.\n");
            else
                printf("\tNenhum valor atribuído a esta posição.\n");
            break;
        case 4:
            printTable(table);
            break;
        case 5:
            randomTable(table);
            break;
        case 6:
            randomValue(table);
            break;
        case 7:
            initializeTable(table);
        default:
            printf("\tOpção inválida.\n");
            break;
        }
    } while (option != 0);
    
    return 0;
}