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
    // Variant 1: Increased computational intensity by unrolling the loop and adding extra arithmetic operations
    // Loop unrolled by a factor of 2 to reduce loop overhead and increase operation count per iteration
    product *= (a + 2) / 2;  // Handle initial step if n >= 2
    for (k = 3; k <= n; k += 2) {
        double term1 = (a + k) / k;
        double term2 = (a + (k + 1)) / (k + 1);
        product *= (term1 * term2);  // Combine two iterations with additional multiplication
    }
    // Handle odd n: if n is odd and loop ended at k == n+1, then k-1 was not processed
    if ((n >= 3) && ((n - 2) % 2 != 0)) {
        product /= (a + n + 1) / (n + 1);  // Undo last extra multiplication if needed
    }
}
