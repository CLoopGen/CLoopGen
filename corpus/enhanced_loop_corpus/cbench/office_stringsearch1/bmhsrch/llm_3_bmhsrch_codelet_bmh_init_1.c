#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse indirect access via index remapping
    // Access pattern is reversed and uses an auxiliary logical offset array
    // to simulate indirect traversal without additional data structures.
    // We iterate forward but process elements from end to start.

    for (i = 0; i < patlen; ++i) {
        int rev_index = patlen - 1 - i;  // Indirect reverse indexing
        uchar current_char = pat[rev_index];
        skip[current_char] = i;  // because patlen - rev_index - 1 == i
    }
}
