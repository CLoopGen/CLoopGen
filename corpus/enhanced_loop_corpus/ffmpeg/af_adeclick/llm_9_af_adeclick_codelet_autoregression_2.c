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
    for (i = 1; i <= ar_order; i++) {
        double sum = 0.0;
        for (j = 0; j < i && j < 5; j++) {
            sum += a[j];
        }
        k[i] = sum / (i < 5 ? i : 5);
    }
}
