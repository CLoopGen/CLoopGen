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
    double local_term = term;
    int step;
    for (ii = 0; ii < n1; ii++) {
        for (step = 0; step < 3; step++) {
            local_term = qq * (qq / (aa - 4. * (ii + 1) * (ii + 1) - local_term));
        }
    }
    term = local_term;
}
