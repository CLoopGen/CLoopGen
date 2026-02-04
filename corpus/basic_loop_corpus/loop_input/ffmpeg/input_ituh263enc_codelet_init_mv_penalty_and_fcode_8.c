#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t umv_fcode_tab[8193];
int mv;

void init_vars() {
    for (int i = 0; i < 8193; i++) {
        umv_fcode_tab[i] = 0;
    }
    mv = 0;
}