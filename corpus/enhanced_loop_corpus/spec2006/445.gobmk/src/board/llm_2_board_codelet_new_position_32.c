#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride for both arrays
    // Instead of sequential access, we traverse with a stride of 3 to create non-unit stride access
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = start; pos < end; pos += 3) {
        if ((board[pos] != 3))
            string_number[pos] = -1;
    }
    // Handle remaining positions not covered by stride using a second loop segment
    for (pos = start + 1; pos < end; pos += 3) {
        if ((board[pos] != 3))
            string_number[pos] = -1;
    }
    for (pos = start + 2; pos < end; pos += 3) {
        if ((board[pos] != 3))
            string_number[pos] = -1;
    }
}
