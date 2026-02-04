#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[2];
    for (i = 1; i <= order; i++) {
        temp[0] = p[i][1];        
        p[i][0] = temp[0];        
        p[i][1] = 0.;             
    }
}
