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
    int j = i;
    int value = nlsf[i];
    for (; j > 0; j--) {
        if (nlsf[j - 1] <= value) break;
        nlsf[j] = nlsf[j - 1];
    }
    nlsf[j] = value;
}
}
