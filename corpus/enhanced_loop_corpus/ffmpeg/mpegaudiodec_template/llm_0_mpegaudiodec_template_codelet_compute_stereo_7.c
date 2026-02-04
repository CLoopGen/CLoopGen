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
int j;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 576; i++) {
        tmp0 = tab0[i];
        tmp1 = tab1[i];
        tab0[i] = tmp0 + tmp1;
        tab1[i] = tmp0 - tmp1;
    }
}
}
