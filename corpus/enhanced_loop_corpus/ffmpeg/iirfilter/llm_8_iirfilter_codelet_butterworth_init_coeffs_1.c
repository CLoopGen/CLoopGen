#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= order && i < 31; i++) {
        p[i][0] = p[i][1] = 0.;
        p[i][0] += i * 0.5;
        p[i][1] -= i * 0.25;
    }
}
