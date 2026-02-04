#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j++) {
        const int idx = ldb * i + j;
        const float B00_real = (((float *)B)[2 * idx]);
        const float B00_imag = (((float *)B)[2 * idx + 1]);
        const float B10_real = (((float *)B)[2 * (idx + ldb)]);
        const float B10_imag = (((float *)B)[2 * (idx + ldb) + 1]);

        (((float *)B)[2 * idx]) = alpha_real * B00_real;
        (((float *)B)[2 * idx + 1]) = alpha_real * B00_imag;

        (((float *)B)[2 * (idx + ldb)]) = alpha_real * B10_real;
        (((float *)B)[2 * (idx + ldb) + 1]) = alpha_real * B10_imag;
    }
}
}
