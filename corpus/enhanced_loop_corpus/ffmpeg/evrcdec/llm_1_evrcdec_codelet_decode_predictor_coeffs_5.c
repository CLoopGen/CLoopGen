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
    i = 0;
    for (int inner_iter = 0; inner_iter < 10 / 2; inner_iter++) {
        for (; i <= inner_iter; i++) {
            a[i + 1] = a[i] - 2 * lsp[i * 2] * a1[i] + a2[i];
            b[i + 1] = b[i] - 2 * lsp[i * 2 + 1] * b1[i] + b2[i];
            a2[i] = a1[i];
            a1[i] = a[i];
            b2[i] = b1[i];
            b1[i] = b[i];
        }
    }
    if (k)
        ilpc[k - 1] = 2. * (a[10 / 2] + b[10 / 2]);
}
}
