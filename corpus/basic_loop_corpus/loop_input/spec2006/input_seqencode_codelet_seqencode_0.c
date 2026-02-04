#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};

struct iupactype iupac[18];

char *str;
int idx;

void init_vars() {
    for (int i = 0; i < 18; i++) {
        iupac[i].sym = 'A' + i;
        iupac[i].symcomp = 'Z' - i;
        iupac[i].code = 'a' + i;
        iupac[i].comp = 'z' - i;
    }

    size_t data_size = 16 * 1024 * 1024;
    str = (char*)malloc(data_size);
    if (!str) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(str, 'R', data_size - 1);
    str[data_size - 1] = '\0';

    iupac[17].sym = 'R';
}