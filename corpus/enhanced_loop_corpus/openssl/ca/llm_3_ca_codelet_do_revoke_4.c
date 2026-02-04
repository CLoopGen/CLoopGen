#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array
    int indices[6] = {0, 1, 2, 3, 4, 5};
    for (i = 0; i < 6; i++) {
        row[indices[i]] = ((void *)0);
    }
}
