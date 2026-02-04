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
double buffer[4] = {0}; // Local buffer to simulate strided memory access pattern
int buf_idx = 0;

for (i = nexp; i >= 1; i--) {
    double xk_inv = 1. / xk;
    buffer[buf_idx % 4] = (((((120. * xk_inv + 120.) * xk_inv + 60.) * xk_inv + 20.) * xk_inv + 5.) * xk_inv + 1.) / rk;
    
    sum *= ex;
    sum += buffer[(buf_idx - 2 + 4) % 4]; // Strided access: use value from two iterations ago

    buf_idx++;
    rk -= 1.;
    xk -= x;
}

// Final flush of delayed terms (if needed, depending on context)
// Note: For strict equivalence, accumulation delay would require adjustment; this variant simulates strided memory behavior.
}
