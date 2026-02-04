#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Expanded trip count with minimal computation, emphasizing memory writes over arithmetic
    for (i = 2; i < 12; i += 1) {
        if (i < 9)
            equot[i] = i % 4 == 0 ? (unsigned short)(i / 2) : 0;
    }
}
