#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= n - 1; k++) {
        if (k % 2 == 0) {
            k_term *= -y / (k * (n - k));
        } else {
            k_term *= y / (k * (n - k));
        }
        sum1 += k_term;
    }
}
