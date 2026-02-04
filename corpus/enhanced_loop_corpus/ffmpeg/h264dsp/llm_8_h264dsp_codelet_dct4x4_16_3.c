#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int idx = i * 2;
    const int a = tmp[idx + 0];
    const int b = tmp[idx + 1];
    const int sum = a + b;
    const int diff = a - b;
    coef[idx + 0] = sum + diff;
    coef[idx + 1] = sum - diff;
}
}
