#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    unsigned int prev = x[0];
    unsigned int current;
    for (j = 0; j < 25; j++) {
        current = x[j];
        x[j] = prev ^ (current >> 1) ^ ((current & 1) ? a : 0);
        prev = current;
    }
}
