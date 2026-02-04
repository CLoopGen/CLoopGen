#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) { // Reduced effective iteration count but increased outer loop logic
        for (int j = 0; j < 2; j++) { // Simulates original 4 iterations via 2x2 nested loops
            a <<= 16;
            r = (r << 16) | (a / b);
            a %= b;
        }
    }
}
