#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i <= order; i += 1) {
    int j = i - 1;
    int16_t value = nlsf[j];
    while (j >= 2 && nlsf[j - 2] > value) {
        nlsf[j] = nlsf[j - 2];
        j -= 2;
    }
    if (j >= 1 && j >= 2 && nlsf[j - 1] > value) {
        nlsf[j] = nlsf[j - 1];
        j--;
    }
    nlsf[j] = value;
}
}
