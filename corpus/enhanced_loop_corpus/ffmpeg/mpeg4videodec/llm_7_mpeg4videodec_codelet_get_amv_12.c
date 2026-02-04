#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern int mb_v;
extern int sum;
extern int dx;
extern int dy;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_sum = sum;
for (y = 0; y < 16; y++) {
    int v_base = mb_v + (unsigned int)dy * y;
    for (x = 0; x < 16; x++) {
        int v = v_base + dx * x;
        temp_sum += v >> shift;
    }
}
sum = temp_sum;
}
