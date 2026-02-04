#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int under_control[400];
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, traverse the array with a stride of 2
    // Adjust loop bounds to stay within valid range
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 2) {
        if (!(board[pos] != 3))
            continue;
        else if (distance[pos] == -1)
            under_control[pos] = 0;
        else
            under_control[pos] = 1;
    }
    // Handle remaining odd indices if needed to maintain correctness
    for (pos = start + 1; pos < end; pos += 2) {
        if (!(board[pos] != 3))
            continue;
        else if (distance[pos] == -1)
            under_control[pos] = 0;
        else
            under_control[pos] = 1;
    }
}
