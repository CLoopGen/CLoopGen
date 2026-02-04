#include <stdio.h>
#include <stdlib.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *x;
int32 i;
int32 veclen;
float32 *m1;
float32 *v1;
float64 dval1;
float64 diff1;

void init_vars() {
    veclen = 65536; // Approximately 256KB of data per array, ensuring ~0.01s runtime
    x = (float32*)calloc(veclen, sizeof(float32));
    m1 = (float32*)calloc(veclen, sizeof(float32));
    v1 = (float32*)calloc(veclen, sizeof(float32));

    dval1 = 1000.0;
    for (i = 0; i < veclen; i++) {
        x[i] = 1.0f + i * 0.01f;
        m1[i] = 0.5f + i * 0.005f;
        v1[i] = 0.1f;
    }
}