#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int len;
extern int pos;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size 2
    // Process pairs of elements with a fixed stride to change access pattern
    // This variant still swaps symmetric positions but in a strided manner
    int stride = 2;
    int limit = (len / 2 + stride - 1) / stride; // Number of iterations for strided access
    for (pos = 0; pos < limit; pos++) {
        int i = pos * stride;
        // First element in stride group
        if (i < len / 2) {
            c = s2[len - i - 1];
            s1[len - i - 1] = s2[i];
            s1[i] = c;
        }
        // Second element in stride group
        if (i + 1 < len / 2) {
            c = s2[len - (i + 1) - 1];
            s1[len - (i + 1) - 1] = s2[i + 1];
            s1[i + 1] = c;
        }
    }
}
