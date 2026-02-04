#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 anum;
extern long *tmpl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal using index-based access
    long *start = tmpl;
    for (I32 i = (anum / sizeof(long)) - 1; i >= 0; i--)
        start[i] = ~start[i];
    anum = 0; // Ensure condition is satisfied after full traversal
}
