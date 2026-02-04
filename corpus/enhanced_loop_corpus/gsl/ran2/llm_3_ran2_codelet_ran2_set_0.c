#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  long m1;
extern  long a1;
extern  long q1;
extern  long r1;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long access_pattern[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Strided then odd indices
    long temp_vals[8];
    temp_vals[0] = s;
    for (i = 0; i < 8; i++) {
        int idx = access_pattern[i];
        long h = temp_vals[idx % (i + 1)] / q1;
        long t = a1 * (temp_vals[idx % (i + 1)] - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        temp_vals[(idx + 1) % 8] = t;
    }
    s = temp_vals[7];
}
