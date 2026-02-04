#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t cos_tab[513];
int f[12];
int i;
int64_t temp;

void init_vars() {
    for (int idx = 0; idx < 513; idx++) {
        cos_tab[idx] = (int16_t)(idx * 2);
    }
    for (int idx = 0; idx < 12; idx++) {
        f[idx] = idx * 100;
    }
    i = 0;
    temp = 0;
}