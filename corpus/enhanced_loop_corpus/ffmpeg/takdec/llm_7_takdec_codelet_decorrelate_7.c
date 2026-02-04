#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int i;
extern int order_half;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t a, b;
    for (i = 0; i < order_half; i++) {
        a = p1[i];
        p2[i] = a;          // Introduce WAW dependency: p2[i] written after read of p1[i]
        b = p2[i];          // RAW dependency: b depends on prior write to p2[i]
        p1[i] = a + b;      // WAR/WAW: p1[i] updated after previous reads
    }
}
