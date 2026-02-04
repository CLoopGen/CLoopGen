#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 25 - m && m > 0; i++) {
        uint32_t temp1 = x[i + m];
        uint32_t temp2 = x[i] >> 1;
        uint32_t temp3 = (x[i] & 1) ? a : 0;
        x[i] = temp1 ^ temp2 ^ temp3;
    }
}
