#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25 - m; i++) {
        unsigned int temp = x[i];
        unsigned int rhs = x[i + m] ^ (temp >> 1);
        if (temp & 1)
            rhs ^= a;
        x[i] = rhs;
    }
}
