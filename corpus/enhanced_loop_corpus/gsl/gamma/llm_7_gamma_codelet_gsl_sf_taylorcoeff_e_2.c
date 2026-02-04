#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double x;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = 1.0;
    for (k = 1; k <= n; k++) {
        factor *= (x / k);
        product = factor; // WAW dependency introduced: product is overwritten each iteration
    }
}
