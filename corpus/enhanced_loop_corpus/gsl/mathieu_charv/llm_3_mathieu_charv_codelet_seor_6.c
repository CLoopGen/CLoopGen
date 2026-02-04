#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with local accumulation to simulate data reuse
    // We unroll the loop partially and update term in a forward-dependent manner
    // This increases locality and changes access pattern to favor consecutive iterations
    double temp = term;
    for (ii = 0; ii < n1 - 1; ii += 2) {
        // First iteration step
        temp = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - temp);
        // Second iteration step using updated term
        temp = qq * qq / (aa - (2. * (ii + 1) + 1.) * (2. * (ii + 1) + 1.) - temp);
    }
    // Handle remaining odd iteration if n1 is odd
    if (n1 % 2 == 1) {
        ii = n1 - 1;
        temp = qq * qq / (aa - (2. * ii + 1.) * (2. * ii + 1.) - temp);
    }
    term = temp;
}
