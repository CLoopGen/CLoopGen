#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double y[2100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 1; k <= n; k++) {
        y[k-1] = y[k-1] + 0; // Introduces a read-after-write (RAW) dependency, though value is unchanged
    }
}
