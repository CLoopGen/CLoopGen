#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride of 2
    // Adjust starting index if needed to stay within bounds
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 2) {
        if ((board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
    }
    // Handle remaining odd index if range length is odd
    for (pos = start + 1; pos < end; pos += 2) {
        if ((board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
    }
}
