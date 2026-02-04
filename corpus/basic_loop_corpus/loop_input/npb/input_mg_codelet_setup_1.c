#include <stdio.h>

int nx[12];
int ny[12];
int nz[12];
int lt;
int k;

void init_vars() {
    lt = 11; // ensures k goes from lt-1=10 down to 1, so we access nx[k+1] up to nx[11], which is valid
    for (int i = 1; i <= 11; i++) {
        nx[i] = (i + 1) * 1024;
        ny[i] = (i + 1) * 2048;
        nz[i] = (i + 1) * 4096;
    }
    // Initialize nx[12], ny[12], nz[12] (index 11) to avoid undefined behavior when accessed as k+1 where k=10
    nx[11] = 12 * 1024;
    ny[11] = 12 * 2048;
    nz[11] = 12 * 4096;
}