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
for (k = 0; k <= 20; k += 2) {
    a[0] = k < 4 ? 0.35 : 0;
    b[0] = k < 4 ? k < 2 ? 0.35 : -0.35 : 0;
    for (i = 0; i < 10 / 2; i++) {
        float temp_a = a[i] - 2 * lsp[i * 2] * a1[i] + a2[i];
        float temp_b = b[i] - 2 * lsp[i * 2 + 1] * b1[i] + b2[i];
        a[i + 1] = temp_a;
        b[i + 1] = temp_b;
        a2[i] = a1[i];
        a1[i] = a[i];
        b2[i] = b1[i];
        b1[i] = b[i];
    }
    if (k % 4 == 0 && k > 0)
        ilpc[(k / 4) - 1] = 3. * (a[5] + b[5]);
}

}
