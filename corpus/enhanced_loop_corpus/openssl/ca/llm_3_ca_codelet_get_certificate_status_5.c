#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index map (reverse order access via lookup table)
    int indices[6] = {5, 4, 3, 2, 1, 0}; // Reverse mapping
    int j;
    for (j = 0; j < 6; j++) {
        row[indices[j]] = ((void *)0);
    }
}
