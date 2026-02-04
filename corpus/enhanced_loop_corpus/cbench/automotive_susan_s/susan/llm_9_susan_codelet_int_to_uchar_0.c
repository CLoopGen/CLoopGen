#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count by processing every other element,
    // then performing a second pass in reverse to maintain coverage.
    // This increases spatial complexity and changes access pattern without altering result.
    int i;
    // First pass: even indices forward
    for (i = 0; i < size; i += 2) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
    // Second pass: odd indices backward
    for (i = (size % 2 == 0) ? size - 1 : size - 2; i >= 1; i -= 2) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
}
