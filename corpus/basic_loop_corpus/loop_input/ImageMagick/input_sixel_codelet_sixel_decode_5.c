#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int sixel_palet[1024];

void init_vars() {
    n = 0;
    for (int i = 0; i < 1024; i++) {
        sixel_palet[i] = 0;
    }
}