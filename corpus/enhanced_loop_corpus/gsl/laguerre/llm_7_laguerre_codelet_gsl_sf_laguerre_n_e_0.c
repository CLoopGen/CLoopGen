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
    double local_a = a;
    for (k = 2; k <= n; k++) {
        product *= (local_a + k) / k;
        local_a += 1.0; // Introduces artificial dependency: each iteration depends on modified local_a (WAW-like pattern within loop, though not carried in original)
    }
}
