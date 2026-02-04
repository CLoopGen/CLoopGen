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
    int limit = (n - 1) * (n - 1);
    for (k = 1; k <= limit; k++) {
        int effective_k = (k % (n - 1)) + 1;
        double adjustment = -y / (effective_k * (n - effective_k));
        k_term *= adjustment;
        if (k % 3 == 0) {
            sum1 += k_term;
        }
    }
}
