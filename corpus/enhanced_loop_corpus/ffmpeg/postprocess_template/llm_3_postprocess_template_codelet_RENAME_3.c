#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern uint8_t *p;
extern int s[10];
extern  int QP2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 9; y++) {
    int x;
    int t = s[9 - y]; // Reverse access in array 's'
    uint8_t* temp_p = p + (y << 3) - 1; // Point to end of block and move backward
    for (x = 1; x < 9; x++) {
        temp_p--; // Pre-decrement: reverse sequential access
        if (t & (1 << x)) {
            int f = 0;
            f = (f + 8) >> 4;
            if (*temp_p + QP2 < f)
                *temp_p = *temp_p + QP2;
            else if (*temp_p - QP2 > f)
                *temp_p = *temp_p - QP2;
            else
                *temp_p = f;
        }
    }
}
}
