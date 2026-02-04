#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *tab;
int j;

static int tab_data[1024 * 1024 / sizeof(int)]; // ~1MB of data

void init_vars() {
    tab = tab_data;

    for (int i = 0; i < 1024 * 1024 / sizeof(int); ++i) {
        tab[i] = i;
    }
}