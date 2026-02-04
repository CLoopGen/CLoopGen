#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern int64_t a;
extern AVInteger out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with temporary array and copy (simulates modified access pattern via buffer)
    uint16_t temp[8];
    int idx = 0;
    for (i = 0; i < 8; i++) {
        temp[idx++] = a;
        a >>= 16;
    }
    // Copy from temp to out.v consecutively
    for (i = 0; i < 8; i++) {
        out.v[i] = temp[i];
    }
}
