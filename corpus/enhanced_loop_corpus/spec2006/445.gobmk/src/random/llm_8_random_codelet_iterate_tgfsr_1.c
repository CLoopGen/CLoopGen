#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 25; i += 2) {
        if (i + m - 25 >= 0 && i + m - 25 < 25) {
            x[i] = x[i + m - 25] ^ (x[i] >> 1) ^ ((x[i] & 1) ? a : 0);
        }
        if (i + 1 < 25) {
            x[i + 1] = x[i + 1 + m - 25] ^ (x[i + 1] >> 1) ^ ((x[i + 1] & 1) ? a : 0);
        }
    }
}
