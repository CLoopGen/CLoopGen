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
    for (k = 1; k <= n; k += 2) {
        if (k + 1 <= n) {
            product *= (x / k) * (x / (k + 1));
        } else {
            product *= (x / k);
        }
    }
}
