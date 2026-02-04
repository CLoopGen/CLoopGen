#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long *x;
extern int n;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n > 1) {
    for (i = 1; i < n; i++) {
        long temp_s = s;
        for (int j = 0; j < 3; j++) { // Increase computational intensity with inner unrolled dependency
            const long h = temp_s / 127773;
            const long t = 16807 * (temp_s - h * 127773) - h * 2836;
            temp_s = (t < 0) ? t + 2147483647 : t;
        }
        s = temp_s;
        x[i] = s;
    }
}
}
