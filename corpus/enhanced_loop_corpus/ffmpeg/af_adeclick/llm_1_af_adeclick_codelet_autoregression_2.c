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
if (ar_order >= 1) {
    i = 1;
    for (; i <= ar_order; i++) {
        k[i] = a[i - 1];
    }
}
}
