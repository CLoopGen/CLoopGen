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
    // Variant 2: Reduced computational intensity with modified trip count and simplified arithmetic
    // Only process every 3rd index to reduce total iterations and remove some arithmetic
    if (n < 2) return;
    int step = 3;  // Increase stride to reduce number of iterations
    for (k = 2; k <= n; k += step) {
        // Simplify computation by removing division in favor of additive approximation
        // Approximate (a + k)/k as 1 + a/k, which reduces precision but lowers operation count
        product *= (1.0 + a / k);
    }
}
