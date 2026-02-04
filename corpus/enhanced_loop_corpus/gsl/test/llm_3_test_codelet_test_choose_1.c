#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (reverse order access via indirection)
    int indices[10];
    for (i = 0; i < 10; i++) {
        indices[i] = 9 - i;  // reverse indexing: 9,8,...,0
    }
    for (i = 0; i < 10; i++) {
        count[indices[i]] = 0;
    }
}
