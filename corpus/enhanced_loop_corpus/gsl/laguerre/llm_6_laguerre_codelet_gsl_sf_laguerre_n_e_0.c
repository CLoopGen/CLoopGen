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
    double temp_product = product;
    for (k = 2; k <= n; k++) {
        temp_product *= (a + k) / k;
    }
    product = temp_product;
}
