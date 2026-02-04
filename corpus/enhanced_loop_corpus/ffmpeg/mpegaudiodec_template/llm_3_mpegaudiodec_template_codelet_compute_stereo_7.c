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
int indices[576];
for (int j = 0; j < 576; j++) {
    indices[j] = j;
}
for (int j = 0; j < 576; j++) {
    int idx = indices[j];
    tmp0 = tab0[idx];
    tmp1 = tab1[idx];
    tab0[idx] = tmp0 + tmp1;
    tab1[idx] = tmp0 - tmp1;
}
}
