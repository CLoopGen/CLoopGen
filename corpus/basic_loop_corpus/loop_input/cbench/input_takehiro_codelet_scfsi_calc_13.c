#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

int ch = 0;
III_scalefac_t scalefac[2][2];
int s2 = 0;
int c2 = 0;
int sfb = 0;

void init_vars() {
    ch = 0;
    s2 = 0;
    c2 = 0;
    sfb = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 22; k++) {
                scalefac[i][j].l[k] = (k % 17) * (i + j + 1);
            }
            for (int m = 0; m < 13; m++) {
                for (int n = 0; n < 3; n++) {
                    scalefac[i][j].s[m][n] = (m * n) % 19;
                }
            }
        }
    }

    scalefac[1][ch].l[21] = -1;
    for (int i = 0; i < 21; i++) {
        scalefac[1][ch].l[i] = (i * 31) % 100;
    }
}