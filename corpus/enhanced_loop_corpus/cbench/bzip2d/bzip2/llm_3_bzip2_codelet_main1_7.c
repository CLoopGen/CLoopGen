#include <stdio.h>

#include <inttypes.h>

typedef char Char;

extern Char *progName;
extern Char progNameReally[1034];
extern Char *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Permutation Table
    // Use an array of indices to traverse progNameReally in shuffled order
    // We'll create a small indirect lookup for plausible positions to simulate irregular access
    static uint16_t indices[1034];
    Char *base = &progNameReally[0];
    int len = 0;

    // Precompute index sequence (reverse order as indirect pattern)
    for (len = 0; base[len] != '\x00' && len < 1034; ++len)
        indices[len] = len;

    // Traverse in reverse-indirect order
    for (int i = len - 1; i >= 0; i--) {
        int j = indices[i]; // Indirect access
        if (base[j] == '/') {
            progName = &base[j + 1];
        }
    }
}
