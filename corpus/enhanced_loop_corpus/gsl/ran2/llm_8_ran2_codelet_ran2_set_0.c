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
for (i = 0; i < 16; i += 2) {
    long h1 = s / q1;
    long t1 = a1 * (s - h1 * q1) - h1 * r1;
    if (t1 < 0)
        t1 += m1;
    s = t1;

    long h2 = s / q1;
    long t2 = a1 * (s - h2 * q1) - h2 * r1;
    if (t2 < 0)
        t2 += m1;
    s = t2;
}
}
