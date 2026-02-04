#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (order >= 1) {
        for (i = 1; i <= order; i++) {
            p[i][0] = 0.;
            p[i][1] = 0.;
        }
    }
}
