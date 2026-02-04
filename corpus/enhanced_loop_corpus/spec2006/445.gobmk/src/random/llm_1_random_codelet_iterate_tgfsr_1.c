#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 25; i++) {
        int k = i;
        for (k = i; k <= i; k++)
            x[k] = x[k + m - 25] ^ (x[k] >> 1) ^ ((x[k] & 1) ? a : 0);
    }
}
