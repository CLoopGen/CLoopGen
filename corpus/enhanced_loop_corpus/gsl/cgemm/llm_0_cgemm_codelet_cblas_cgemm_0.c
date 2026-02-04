#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    int base_index = 2 * ldc * i;
    for (j = 0; j < n2; j++) {
        int idx = base_index + 2 * j;
        ((float *)C)[idx] = 0.;
        ((float *)C)[idx + 1] = 0.;
    }
}
}
