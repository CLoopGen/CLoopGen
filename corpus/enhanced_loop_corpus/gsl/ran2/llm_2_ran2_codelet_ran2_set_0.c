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
    long temp_s[8];
    temp_s[0] = s;
    for (i = 0; i < 8; i++) {
        long h = temp_s[i] / q1;
        long t = a1 * (temp_s[i] - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        temp_s[(i + 1) % 8] = t;
    }
    s = temp_s[7];
}
