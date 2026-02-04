#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward skipping every other element)
    // We traverse the char array with a stride of 2, checking only even-indexed positions.
    // To maintain correctness, we ensure that we do not skip necessary updates by adjusting logic accordingly.
    for (int i = 0; p[i] != '\0'; i += 2) {
        if (p[i] == '0' || p[i] == ' ') {
            if (p[i] == '0') {
                q = &p[i];
                p[i] = ' ';
                n--;
            }
        }
        // Handle odd index if next char is valid and matches condition
        if (p[i+1] != '\0' && (p[i+1] == '0' || p[i+1] == ' ')) {
            if (p[i+1] == '0') {
                q = &p[i+1];
                p[i+1] = ' ';
                n--;
            }
        }
    }
}
