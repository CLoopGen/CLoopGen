#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

int pretab[21];
III_scalefac_t *scalefac;
int sfb;

void init_vars() {
    scalefac = (III_scalefac_t*)malloc(sizeof(III_scalefac_t));
    for (int i = 0; i < 22; i++) {
        scalefac->l[i] = (i < 11) ? 0 : (i % 7 + 1) * 5;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 3; j++) {
            scalefac->s[i][j] = i * 3 + j;
        }
    }
    for (int i = 0; i < 21; i++) {
        pretab[i] = (i % 5 + 1) * 6;
    }
    sfb = 0;
}