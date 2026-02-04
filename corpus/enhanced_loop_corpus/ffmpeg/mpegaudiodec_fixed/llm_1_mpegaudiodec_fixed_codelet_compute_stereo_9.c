#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *tab0;
extern int *tab1;
extern unsigned int tmp0;
extern unsigned int tmp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 576; i += 2) {
    for (int k = 0; k < 2 && (i + k) < 576; k++) {
        int idx = i + k;
        tmp0 = tab0[idx];
        tmp1 = tab1[idx];
        tab0[idx] = tmp0 + tmp1;
        tab1[idx] = tmp0 - tmp1;
    }
}
}
