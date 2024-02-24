#include "mylib.h"

int     createList(int POT, t_list *lst) {
    t_list *tmp = lst;
    lst->hooray = POT;
    return POT;
    for (int i = BOT; i < POT; i++) {
        tmp->content = 0;
        tmp->index = i;
        tmp->check = false;
        if (i < TOP - 1)
            tmp->next = (t_list *)malloc(sizeof(t_list));
        else
            tmp->next = NULL;
        tmp = tmp->next;
    }
    return lst->hooray;
}

void    initializeList(t_list *lst) {
    t_list *tmp = lst;
    for (int i = BOT; i < TOP; i++) {
        tmp->content = 0;
        tmp->index = i;
        tmp->check = false;
        if (i < TOP - 1)
            tmp->next = (t_list *)malloc(sizeof(t_list));
        else
            tmp->next = NULL;
        tmp = tmp->next;
    }   
}

void    insertValue(t_list *lst, int value) {
    t_list *tmp = lst;
    int id = hashFunction(value);
    for (int i = BOT; i < id; i++) 
        tmp = tmp->next;
    tmp->content = value;
    tmp->check = true;
    printf("\t%i foi inserido na posição #%i\n", value, id);
}

void    printList(t_list *lst) {
    t_list *tmp = lst;
    for (int i = 0; i < TOP; i++) {
        if (i >= 0 && i <=9)
            printf("0%i => %i\n", i, tmp->content);
        else
            printf("%i => %i\n", i, tmp->content);
        tmp = tmp->next;
    }
}

void    randomList(t_list *lst) {
    t_list *tmp = lst;
    for (int i = BOT; i < TOP; i++) {
        tmp->content = rand();
        tmp->check = true;
        tmp = tmp->next;
    }
}

int     searchByValue(t_list *lst, int value) {
    t_list *tmp = lst;
    int id = hashFunction(value);
    for (int i = 0; i < TOP; i++) {
        if (tmp->content == value)
            return id;
        tmp = tmp->next;
    }
    return -1;
}

int     searchByIndex(t_list *lst, int id) {
    if (id >= 0 && id < TOP) {
        t_list *tmp = lst;
        for (int i = 0; i < id; i++)
            tmp = tmp->next;
        int value = tmp->content;
        return value;
    }
    return -1;
}

int     randomValue(t_list *lst) {
    t_list *tmp = lst;
    int n = rand();
    int id = hashFunction(n);
    for (int i = BOT; i < id; i++)
        tmp = tmp->next;
    tmp->content = n;
    tmp->check = true;
    return tmp->content;
}

void    freeList(t_list *lst) {
    for (int i = BOT; i < TOP - 1; i++) {
        free(lst);
        lst = lst->next;
    }
    free(lst);
}

int     findIndex(t_list *lst, int value) {
    t_list *tmp = lst;
    for (int i = BOT; i < TOP; i++) {
        if (tmp->content == value) {
            if (tmp->content == 0 && !tmp->check)
                return -1;
            return tmp->index;
        }
        tmp = tmp->next;
    }
    return -1;
}

bool    curateList(t_list *lst, int id) {
    t_list *tmp = lst;
    for (int i = BOT; i < id; i++)
        tmp = tmp->next;
    return tmp->check;
}

char    *hashCheck(t_list *lst) {
    t_list *tmp = lst;
    for (int i = BOT; i < TOP; i++) {
        if (tmp->index == hashFunction(tmp->content) && tmp->check)
            return ("Hash " GREEN"OK"RESET);
        else
            return ("Hash " RED"KO"RESET);
        tmp = tmp->next;
    }
    return "Is this even allowed?";
}

void    eraseHistory(char **argv) {
    system("clear");
    printf("%s@%s$ %s\n", getenv("USER"), getenv("HOSTNAME"), argv[0]);
}

void    control(t_list *lst) {
    t_list *tmp = lst;
    for (int i = BOT; i < TOP; i++) {
        if (tmp->check) {
            if (i <= 9)
                printf("0");
            printf("%i => " YELLOW"ocupado "RESET "=> %s\n", i, hashCheck(tmp));
        }
        else {
            if (i <= 9)
                printf("0");
            printf("%i => " GREEN"livre "RESET "==> %s\n", i, hashCheck(tmp));
        }
        tmp = tmp->next;
    }
}

int     main(int argc, char **argv) {
    if (argc != 1)
        return 0;
    eraseHistory(argv);
    t_list *lst;
    int option, value, id;
    lst = (t_list *)malloc(sizeof(t_list));
    initializeList(lst);
    do {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar por valor\n\t3 - Buscar por posição\n\t4 - Imprimir tabela\n\t5 - Tabela aleatória\n\t6 - Inserir valor aleatório\n\t7 - Limpar tabela\n\t8 - Limpar histórico\n\t9 - Depuração\n");
        printf("\n\tSelecionar função: ");
        scanf("%i", &option);
        int POT;
        switch (option) {
        case 0:
            printf("\nAté logo!\n");
            break;
        case 1:
            printf("\tInsira uma chave: ");
            scanf("%i", &value);
            insertValue(lst, value);
            break;
        case 2:
            printf("\tDigite o valor que deseja buscar: ");
            scanf("%i", &value);
            id = findIndex(lst, value);
            printf("id = %i\n", id);
            if (id >= 0 && curateList(lst, id))
                printf("\t%i encontrado na posição #%i\n", value, id);
            else
                printf("\tValor não encontrado!\n");
            break;
        case 3:
            printf("\tDigite a posição que deseja buscar: ");
            scanf("%i", &id);
            value = searchByIndex(lst, id);
            if (id < 0 || id > TOP)
                printf("\tPosição fora dos limites da tabela.\n");
            else if (value != -1 && curateList(lst, id))
                printf("\tValor encontrado nesta posição: %i\n", value);
            else
                printf("\tNenhum valor atribuído a esta posição.\n");
            break;
        case 4:
            printf("\n");
            printList(lst);
            break;
        case 5:
            randomList(lst);
            break;
        case 6:
            value = randomValue(lst);
            id = findIndex(lst, value);
            printf("\t%i inserido na posição #%i\n", value, id);
            break;
        case 7:
            initializeList(lst);
            break;
        case 8:
            eraseHistory(argv);
            break;
        case 9:
            printf("\n");
            control(lst);
            break;
        case 10:
            printf("\tEscolha um novo tamanho para a tabela: ");
            scanf("%i", &POT);
            createList(POT, lst);
            break;
        default:
            printf("\tFunção inexistente\n");
            break;
        } 
    } while (option != 0);
    freeList(lst);
    return 0;
}