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
    for (k = 1; k <= n - 1; k += 2) {
        double temp1 = -y / (k * (n - k));
        k_term *= temp1;
        sum1 += k_term;

        if (k + 1 < n) {
            double temp2 = -y / ((k + 1) * (n - (k + 1)));
            k_term *= temp2;
            sum1 += k_term;
        }
    }
}
