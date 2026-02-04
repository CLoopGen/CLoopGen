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
        for (j = 0; j < n2; j++) {
            int index = 2 * (ldc * i + j);
            ((float *)C)[index] = 0.;
            ((float *)C)[index + 1] = 0.;
        }
    }
}
