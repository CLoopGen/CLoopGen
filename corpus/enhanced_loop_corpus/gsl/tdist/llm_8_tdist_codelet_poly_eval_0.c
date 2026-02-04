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
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            y = x * (x * (y + c[i]) + c[i + 1]);
        } else {
            y = x * (y + c[i]);
        }
    }
}
