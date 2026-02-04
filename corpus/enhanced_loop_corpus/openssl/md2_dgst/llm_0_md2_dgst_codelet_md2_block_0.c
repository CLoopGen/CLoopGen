#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 4; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            // Nested loop body intentionally empty
        }
    }
}
