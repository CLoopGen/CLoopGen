#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char **row;
char **irow;
int i;

#define ARRAY_SIZE 512
#define STRING_SIZE 256

static char *allocate_string() {
    char *str = (char *)malloc(STRING_SIZE);
    if (str) {
        memset(str, 'A', STRING_SIZE - 1);
        str[STRING_SIZE - 1] = '\0';
    }
    return str;
}

void init_vars() {
    row = (char **)calloc(ARRAY_SIZE, sizeof(char *));
    irow = (char **)calloc(ARRAY_SIZE, sizeof(char *));
    if (!row || !irow) {
        exit(1);
    }

    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        row[idx] = allocate_string();
        irow[idx] = NULL;
    }
}