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
for (i = 0; i < 1152; i++) {
    if (i % 2 == 0) {
        tmp0 = tab0[i/2];
        tmp1 = tab1[i/2];
        tab0[i/2] = tmp0 + tmp1 + 1;
        tab1[i/2] = tmp0 - tmp1 - 1;
    }
}
}
