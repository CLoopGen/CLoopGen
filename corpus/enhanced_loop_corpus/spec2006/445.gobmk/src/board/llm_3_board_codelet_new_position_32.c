#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping using a lookup table
    // Simulate indirect access by precomputing valid indices in reverse order
    int indices[400];
    int count = 0;
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    // Precompute access indices in reverse to alter spatial locality
    for (int i = end - 1; i >= start; i--) {
        indices[count++] = i;
    }
    // Traverse using the precomputed (indirect) indices
    for (int i = 0; i < count; i++) {
        pos = indices[i];
        if ((board[pos] != 3))
            string_number[pos] = -1;
    }
}
