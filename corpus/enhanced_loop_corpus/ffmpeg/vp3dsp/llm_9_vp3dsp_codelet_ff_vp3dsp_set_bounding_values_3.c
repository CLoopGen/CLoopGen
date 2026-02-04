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
    // Variant 2: Reduced computational intensity with simplified operations and increased trip count via smaller step
    for (x = value = filter_limit; x < 192 && value > 0; x++, value--) {
        bounding_values[x & 127] = (int8_t)value;  // Mask index and cast value to reduce range impact
        if (x % 4 == 0) {  // Less frequent symmetric update
            bounding_values[(-x) & 127] = (int8_t)(-value);
        }
    }
}
