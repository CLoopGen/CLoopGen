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
    for (ii = 0; ii < n1; ii++) {
        double index_sq = (ii + 1) * (ii + 1);
        double adjusted_aa = aa - 4. * index_sq;
        if (adjusted_aa > term) {
            term = qq * qq / (adjusted_aa - term);
        } else {
            term = -term;
        }
    }
}
