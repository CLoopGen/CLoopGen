#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int *surround_size;
extern char mn[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the board with a stride of 2
    // Adjust loop bounds to stay within valid range
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 2) {
        if ((board[pos] != 3) && mn[pos] == 1)
            (*surround_size)++;
    }
    // Handle remaining odd index if needed, but since we want only one loop and no while,
    // we use a second forward pass with offset start if the range allows
    for (pos = start + 1; pos < end; pos += 2) {
        if ((board[pos] != 3) && mn[pos] == 1)
            (*surround_size)++;
    }
}
