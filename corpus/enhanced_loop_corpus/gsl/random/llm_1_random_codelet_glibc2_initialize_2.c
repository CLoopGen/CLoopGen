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
    // Outer loop splitting the original range into chunks to increase nesting
    const int chunk_size = 2;
    for (int k = 1; k < n; k += chunk_size) {
        for (i = k; i < n && i < k + chunk_size; i++) {
            const long h = s / 127773;
            const long t = 16807 * (s - h * 127773) - h * 2836;
            if (t < 0) {
                s = t + 2147483647;
            } else {
                s = t;
            }
            x[i] = s;
        }
    }
}
