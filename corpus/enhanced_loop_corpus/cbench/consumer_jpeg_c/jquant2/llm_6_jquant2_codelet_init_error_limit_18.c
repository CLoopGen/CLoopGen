#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_in = in;
    for (; temp_in <= 255; temp_in++) {
        int temp_out = out + (temp_in - in); // Introduce RAW: temp_out depends on temp_in
        table[temp_in] = temp_out;
        table[-temp_in] = -temp_out;
    }
    in = temp_in; // Update original in after loop
}
