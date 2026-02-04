#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (order <= 1) return;
for (i = 2; i < order; i += 2) {
    int j, value1 = nlsf[i], value2 = nlsf[i-1];
    int pos1 = i, pos2 = i-1;
    for (j = i - 2; j >= 0 && nlsf[j] > value1; j--) {
        nlsf[j + 2] = nlsf[j];
        pos1 = j + 2;
        pos2 = j + 1;
    }
    nlsf[pos1] = value1;
    nlsf[pos2] = value2;
}
}
