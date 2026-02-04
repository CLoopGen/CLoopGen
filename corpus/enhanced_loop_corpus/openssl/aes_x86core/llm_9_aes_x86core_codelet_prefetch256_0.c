#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 64 / sizeof(t[0]); i++) {
        for (int j = 0; j < 4; j++) {
            sum ^= t[i] ^ (t[i] + j);
        }
    }
}
