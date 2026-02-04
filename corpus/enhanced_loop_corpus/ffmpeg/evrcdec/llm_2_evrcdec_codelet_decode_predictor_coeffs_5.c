#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *ilpc;
extern double lsp[10];
extern float a[6];
extern float b[6];
extern float a1[5];
extern float a2[5];
extern float b1[5];
extern float b2[5];
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= 10; k++) {
    a[0] = k < 2 ? 0.25 : 0;
    b[0] = k < 2 ? k < 1 ? 0.25 : -0.25 : 0;
    for (i = 0; i < 10 / 2; i++) {
        int idx = i;
        a[idx + 1] = a[idx] - 2 * lsp[idx * 2] * a1[idx] + a2[idx];
        b[idx + 1] = b[idx] - 2 * lsp[idx * 2 + 1] * b1[idx] + b2[idx];
        a2[idx] = a1[idx];
        a1[idx] = a[idx];
        b2[idx] = b1[idx];
        b1[idx] = b[idx];
    }
    if (k)
        ilpc[k - 1] = 2. * (a[10 / 2] + b[10 / 2]);
}
}
