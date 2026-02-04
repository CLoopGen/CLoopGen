#include <stdio.h>

#include <inttypes.h>

extern int *ref;
extern char *k1;
extern int col;
extern int r1;
extern int *canons1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing k1 and ref sequentially, use a stride of 2 to create strided access.
    // This changes memory access pattern to non-consecutive elements, potentially affecting cache behavior.
    for (col = 0; k1[col] != '\x00'; col += 2) {
        if (!((k1[col]) == ' ' || (k1[col]) == '.' || (k1[col]) == '_' || (k1[col]) == '-' || (k1[col]) == '~')) {
            canons1[r1] = ref[col] ? 1 : 0;
            r1++;
        }
        // Ensure we don't go out of bounds on odd-length strings
        if (k1[col + 1] != '\x00' && col + 1 < __builtin_strlen((char*)k1)) {
            if (!((k1[col + 1]) == ' ' || (k1[col + 1]) == '.' || (k1[col + 1]) == '_' || 
                  (k1[col + 1]) == '-' || (k1[col + 1]) == '~')) {
                canons1[r1] = ref[col + 1] ? 1 : 0;
                r1++;
            }
        }
    }
}
