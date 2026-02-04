#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n >= 2) {
        k = 2;
        for (int outer = k; outer <= n; outer++) {
            product *= (a + outer) / outer;
        }
    }
}
