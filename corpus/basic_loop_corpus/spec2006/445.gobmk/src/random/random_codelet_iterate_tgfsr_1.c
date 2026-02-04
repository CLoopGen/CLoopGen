#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; i < 25; i++)
    x[i] = x[i + m - 25] ^ (x[i] >> 1) ^ ((x[i] & 1) ? a : 0);

}
