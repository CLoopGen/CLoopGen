#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int sixel_default_color_table[16];
int n;
int sixel_palet[1024];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        sixel_default_color_table[i] = rand() % 256;
    }
    for (int i = 0; i < 1024; i++) {
        sixel_palet[i] = 0;
    }
    n = 0;
}