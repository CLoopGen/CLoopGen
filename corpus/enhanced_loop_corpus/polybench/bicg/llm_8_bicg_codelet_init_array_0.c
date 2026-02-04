#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double p[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < m && m > 0; i++) {
        double temp1 = (double)(i % m);
        double temp2 = temp1 / m;
        double temp3 = temp2 * temp2;
        p[i] = temp3 + temp2;
    }
}
