#ifndef MYLIB_H
# define MYLIB_H

//Variáveis globais
# define TOP 31
# define BOT 0
# define DRAND_MAX 9999

// Códigos de cor
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

//includes básicos
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <strings.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_lst {
    int content;
    int index;
    int hooray;
    bool check;
    struct s_lst *next;
    struct s_lst *previous;
}              t_list;

int     hashFunction(int value) {
    return value % TOP;
}

#endif