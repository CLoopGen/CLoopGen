#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = i; j < 50; j++) {
        int idx = j % 25;
        unsigned int temp = x[idx];
        temp = temp ^ (temp >> 1) ^ ((temp & 1) ? a : 0);
        x[idx] = x[(idx + m - 25 + 25) % 25] ^ temp;
    }
    i = 25; 
}
