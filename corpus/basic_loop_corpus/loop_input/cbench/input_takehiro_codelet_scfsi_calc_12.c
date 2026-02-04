#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

int ch = 1;
III_scalefac_t scalefac[2][2];
int s1 = 0;
int c1 = 0;
int sfb = 0;

void init_vars() {
    ch = 1;
    s1 = 0;
    c1 = 0;
    sfb = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 22; k++) {
                if (k < 11) {
                    scalefac[i][j].l[k] = (i == 1 && j == ch && k % 3 != 0) ? (k * 17 + 5) : -1;
                } else {
                    scalefac[i][j].l[k] = k * 13 + 7;
                }
            }
            for (int m = 0; m < 13; m++) {
                for (int n = 0; n < 3; n++) {
                    scalefac[i][j].s[m][n] = m * 3 + n + 1;
                }
            }
        }
    }
}