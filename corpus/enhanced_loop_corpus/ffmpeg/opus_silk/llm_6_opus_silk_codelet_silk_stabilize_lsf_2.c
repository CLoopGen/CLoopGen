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
    int temp = nlsf[i];
    while (j > 0 && nlsf[j - 1] > temp) {
        nlsf[j] = nlsf[j - 1];
        j--;
    }
    nlsf[j] = temp;
}
}
