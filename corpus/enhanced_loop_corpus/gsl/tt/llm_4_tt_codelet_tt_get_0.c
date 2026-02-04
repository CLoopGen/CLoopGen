#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned long mag01[2];
extern unsigned long * x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25 - 7; i++) {
        if ((x[i] % 2) == 0) {
            x[i] = x[i + 7] ^ (x[i] >> 1);
        } else {
            x[i] = x[i + 7] ^ (x[i] >> 1) ^ mag01[1];
        }
    }
}
