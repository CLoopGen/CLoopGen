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
for (int j = 0; j < 2; j++) {
    for (i = 12 + j; i < len - 1; i += 2) {
        float a = output[i][3] * AL1;
        float b = output[i + 1][0] * AL1;
        output[i][3] += b - a;
        output[i + 1][0] -= b + a;
        a = output[i][2] * AL2;
        b = output[i + 1][1] * AL2;
        output[i][2] += b - a;
        output[i + 1][1] -= b + a;
    }
}
}
