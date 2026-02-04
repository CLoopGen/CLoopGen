#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern int i;
extern double p[31][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i <= order && i < 31; i++) {
        p[i][0] = p[i][1] = 0.;
        for (j = 1; j < i; j++) {
            p[i][0] += (double)(j % 3) * 0.1;
            p[i][1] -= (double)(j % 4) * 0.05;
        }
    }
}
