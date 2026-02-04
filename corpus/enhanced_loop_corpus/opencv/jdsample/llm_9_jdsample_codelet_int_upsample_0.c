#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern JSAMPROW outptr;
extern JSAMPLE invalue;
extern int h;
extern int h_expand;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop with reduced trip count and increased per-iteration operations
    int trip_count = (h_expand + 2 - 1) / 2; // Ceiling of h_expand / 2
    for (h = trip_count; h > 0; h--) {
        *outptr++ = invalue;
        if (--h_expand > 0) {
            *outptr++ = invalue;
            h_expand--;
        }
    }
}
