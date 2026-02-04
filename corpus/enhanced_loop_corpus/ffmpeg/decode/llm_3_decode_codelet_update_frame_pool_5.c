#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with adjusted pointer arithmetic
    // Alters access pattern to process elements from higher to lower indices consecutively
    for (i = 2; i >= 0 && data[i]; i--) {
        size[i] = data[i] - data[i - 1];
    }
}
