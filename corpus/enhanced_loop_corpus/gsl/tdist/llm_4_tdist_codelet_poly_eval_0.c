#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double c[];
extern unsigned int n;
extern double x;
extern unsigned int i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        if (c[i] != 0.0) {
            y = x * (y + c[i]);
        }
    }
}
