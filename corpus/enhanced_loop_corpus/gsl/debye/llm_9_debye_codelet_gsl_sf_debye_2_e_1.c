#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double xk;
extern double rk;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified operations and increased effective trip count via unrolling prevention
    for (i = nexp; i >= 1; i--) {
        sum *= ex;
        sum += (1.0 + 1.5 / xk) / rk;  // Simplified the additive term with fewer operations
        rk -= 1.;
        xk -= x;
        // Additional lightweight operation to alter data flow without increasing complexity significantly
        if (i % 3 == 0) {
            sum *= 1.001;
        }
    }
}
