#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ar_order;
extern double *k;
extern double *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < ar_order; j++) {
    for (i = j + 1; i <= j + 1 && i <= ar_order; i++) {
        k[i] = a[i - 1];
    }
}
}
