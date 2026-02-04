#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing every other element
    // and increase per-iteration work slightly with redundant masking
    for (i = (len + 1) / 2; i > 0; --i) {
        size_t index1 = 2 * i;
        size_t index2 = 2 * i - 1;
        if (index1 <= len) {
            out[index1] = (unsigned char)(bits & 255);
            bits >>= 8;
        }
        if (index2 <= len && bits != 0) {
            out[index2] = (unsigned char)(bits & 255);
            bits >>= 8;
        }
    }
    // Handle odd-length case with a final conditional write if needed
    if (len % 2 == 1 && bits != 0) {
        out[1] = (unsigned char)(bits & 255);
    }
}
