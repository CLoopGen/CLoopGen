#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *tab;
int j;

static int tab_data[1048576]; // 4MB of data (1M integers)

void init_vars() {
    tab = tab_data;

    for (int i = 0; i < 1048576; ++i) {
        tab[i] = rand() % 1000;
    }
}