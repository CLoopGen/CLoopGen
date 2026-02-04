#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t exponent_group_tab[2][3][256];
int expstr;
int i;
int grpsize;

void init_vars() {
    for (int idx0 = 0; idx0 < 2; idx0++) {
        for (int idx1 = 0; idx1 < 3; idx1++) {
            for (int idx2 = 0; idx2 < 256; idx2++) {
                exponent_group_tab[idx0][idx1][idx2] = 0;
            }
        }
    }
    expstr = 0;
    i = 0;
    grpsize = 0;
}