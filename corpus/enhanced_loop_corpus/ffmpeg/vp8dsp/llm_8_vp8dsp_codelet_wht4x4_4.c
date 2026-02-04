#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int idx = i * 2;
    int a1 = coef[idx + 0];
    int b1 = coef[idx + 1];
    int temp = a1 + b1;
    a1 = temp * 2;
    b1 = (temp - (b1 << 1)) * 2;
    coef[idx + 0] = a1;
    coef[idx + 1] = b1;
}
}
