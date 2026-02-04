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
    tmp0 = 0;
    tmp1 = 0;
    for (i = 0; i < 576; i += 2) {
        tmp0 = tab0[i] + tab1[i];
        tmp1 = tab0[i] - tab1[i];
        if (i + 1 < 576) {
            tab0[i] = tmp0;
            tab1[i] = tmp1;
            tmp0 = tab0[i+1] + tab1[i+1];
            tmp1 = tab0[i+1] - tab1[i+1];
            tab0[i+1] = tmp0;
            tab1[i+1] = tmp1;
        } else {
            tab0[i] = tmp0;
            tab1[i] = tmp1;
        }
    }
}
