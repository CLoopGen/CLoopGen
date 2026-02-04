#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int max_v;
extern int *c_array;
extern  int arraysize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
max_v = 0x80000000; // Set to minimum 32-bit signed integer value
for (x = 0; x < arraysize * 2; x++) {
    int idx = x % arraysize;
    int val = c_array[idx];
    int greater = (val > max_v);
    // Use arithmetic instead of branching: (condition ? a : b) -> b + condition*(a - b)
    max_v = max_v + greater * (val - max_v);
}
}
