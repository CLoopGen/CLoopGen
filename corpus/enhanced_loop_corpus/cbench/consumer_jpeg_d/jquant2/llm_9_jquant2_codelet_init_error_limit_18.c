#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = in; i <= 127; i++) {
    int idx = i * 2;
    table[idx] = out ^ i;
    table[-idx] = -(out ^ i);
}
}
