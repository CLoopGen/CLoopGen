#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
        long h = s / q;
        long t = a * (s - h * q) - h * r;
        if (t < 0)
            t += m;
        s = t;
    }
}
}
