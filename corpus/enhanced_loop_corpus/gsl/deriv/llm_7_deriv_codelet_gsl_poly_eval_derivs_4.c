#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern  size_t lenc;
extern double res[];
extern  size_t lenres;
extern size_t i;
extern size_t n;
extern size_t nmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, n = 0, nmax = 0; i < lenres; i++) {
        size_t idx = (n < lenc) ? lenc - 1 : 0;  // Eliminate loop-carried dependency on condition
        res[i] = (n < lenc) ? c[idx] : 0.0;
        // Introduce artificial WAR-like pattern by using n in calculation before increment
        if (n < lenc) {
            nmax = n;      // Write after prior read of n — WAR preserved
            n++;           // Update after use
        }
    }
}
