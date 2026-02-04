#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float float32;
typedef int int32;
typedef double float64;

float32 *x;
int32 veclen;
float32 *m1;
float32 *v1;
float64 dval1;
float64 diff1;
int32 i;

void init_vars() {
    veclen = 25000000;  // Approximately 100 MB of total data (25M elements * ~4 bytes)

    x = (float32*)malloc(veclen * sizeof(float32));
    m1 = (float32*)malloc(veclen * sizeof(float32));
    v1 = (float32*)malloc(veclen * sizeof(float32));

    for (int j = 0; j < veclen; j++) {
        x[j] = (float32)(j % 1000) / 10.0f;
        m1[j] = (float32)((j + 5) % 1000) / 10.0f;
        v1[j] = (float32)((j + 10) % 1000) / 100.0f + 1.0f;
    }

    dval1 = 1e10;
    diff1 = 0.0;
    i = 0;
}