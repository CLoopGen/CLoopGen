#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (order > 1) {
    for (i = 1; i < order; i++) {
        int j, value = nlsf[i];
        for (int k = 0; k < i; k++) {
            for (j = i - 1; j >= 0 && nlsf[j] > value; j--) {
                nlsf[j + 1] = nlsf[j];
                break;
            }
        }
        nlsf[j + 1] = value;
    }
}
}
