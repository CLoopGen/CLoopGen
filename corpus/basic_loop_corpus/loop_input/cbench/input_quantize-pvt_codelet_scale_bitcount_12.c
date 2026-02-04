#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

int pretab[21] = {0};

III_scalefac_t scalefac_data;
III_scalefac_t *scalefac = &scalefac_data;

int sfb;

void init_vars() {
    for (int i = 0; i < 21; i++) {
        pretab[i] = i * 100;
    }
    for (int i = 0; i < 22; i++) {
        scalefac->l[i] = i * 1000;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 3; j++) {
            scalefac->s[i][j] = i * 3 + j;
        }
    }
    sfb = 0;
}