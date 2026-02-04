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
for (i = 0; i < 4; i++) {
    long h = s / q1;
    long diff = s - h * q1;
    long mul1 = a1 * diff;
    long mul2 = h * r1;
    long t = mul1 - mul2;
    t = (t < 0) ? t + m1 : t;
    s = t;
}
}
