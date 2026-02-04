#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float output[32][4];
extern ptrdiff_t len;
extern float AL1;
extern float AL2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant: Strided memory access with step of 2 to increase data reuse and change access pattern
for (i = 12; i < len - 1; i += 2) {
    float a = output[i][3] * AL1;
    float b = output[i + 1][0] * AL1;
    output[i][3] += b - a;
    output[i + 1][0] -= b + a;
    a = output[i][2] * AL2;
    b = output[i + 1][1] * AL2;
    output[i][2] += b - a;
    output[i + 1][1] -= b + a;

    // Second iteration simulated within same loop step if within bounds
    if (i + 1 < len - 1) {
        int j = i + 1;
        a = output[j][3] * AL1;
        b = output[j + 1][0] * AL1;
        output[j][3] += b - a;
        output[j + 1][0] -= b + a;
        a = output[j][2] * AL2;
        b = output[j + 1][1] * AL2;
        output[j][2] += b - a;
        output[j + 1][1] -= b + a;
    }
}
}
