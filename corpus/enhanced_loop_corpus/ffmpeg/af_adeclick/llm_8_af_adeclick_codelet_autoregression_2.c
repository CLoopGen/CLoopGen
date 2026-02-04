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
    for (i = 1; i <= ar_order; i += 2) {
        if (i + 1 <= ar_order) {
            k[i] = a[i - 1] * 2.0;
            k[i + 1] = a[i] * 2.0;
        } else {
            k[i] = a[i - 1] * 2.0;
        }
    }
}
