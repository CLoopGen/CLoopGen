#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

III_scalefac_t scalefac_data;
III_scalefac_t *scalefac = &scalefac_data;
int sfb;
int max_slen1;

void init_vars() {
    max_slen1 = 0;
    for (int i = 0; i < 22; i++) {
        scalefac->l[i] = (i < 11) ? (i * 3 + 1) * 7 : 0;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 3; j++) {
            scalefac->s[i][j] = i * 3 + j;
        }
    }
}