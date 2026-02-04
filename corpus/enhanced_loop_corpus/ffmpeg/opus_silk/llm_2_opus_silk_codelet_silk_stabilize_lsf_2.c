#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < order; i++) {
    int j, value = nlsf[i];
    int16_t *base = &nlsf[0];
    for (j = i - 1; j >= 0 && base[j] > value; j--)
        base[j + 1] = base[j];
    base[j + 1] = value;
}
}
