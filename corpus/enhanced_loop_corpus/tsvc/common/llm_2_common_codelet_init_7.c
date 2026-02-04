#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32000; i = i + 5) {
    int base = i;
    (*ip)[base]     = base + 4;
    (*ip)[base + 1] = base + 2;
    (*ip)[base + 2] = base;
    (*ip)[base + 3] = base + 3;
    (*ip)[base + 4] = base + 1;
}
}
