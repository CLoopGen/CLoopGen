#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned int temp[25];
    for (j = 0; j < 25; j++)
        temp[j] = x[(j + m) % 25] ^ (x[j] >> 1) ^ ((x[j] & 1) ? a : 0);
    for (j = 0; j < 25; j++)
        x[j] = temp[j];
}
