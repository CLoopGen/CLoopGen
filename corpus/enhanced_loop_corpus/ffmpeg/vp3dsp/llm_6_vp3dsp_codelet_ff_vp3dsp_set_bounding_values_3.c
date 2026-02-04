#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_value = value;
    for (x = temp_value; x < 128 && temp_value > 0; x++, temp_value--) {
        bounding_values[x] = temp_value;
        bounding_values[-(x + 1)] = -(temp_value - 1); // Introduces WAR dependency on 'temp_value' and breaks direct WAW on negative index
    }
}
