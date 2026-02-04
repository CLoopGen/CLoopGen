#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_out = out;
    for (; in <= 255; in++) {
        table[in] = temp_out;
        temp_out++; // Introduce WAW dependency on temp_out (loop-carried)
        table[-in] = -temp_out;
    }
}
