#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 xr[2][576];
FLOAT8 xr_org[2][576];
int i;

void init_vars() {
    for (int ch = 0; ch < 2; ch++) {
        for (int j = 0; j < 576; j++) {
            xr_org[ch][j] = (ch + 1) * (j + 1) * 0.5;
        }
    }
}