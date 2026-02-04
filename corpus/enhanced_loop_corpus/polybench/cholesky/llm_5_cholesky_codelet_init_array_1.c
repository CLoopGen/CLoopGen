#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < n; ++r)
        for (s = 0; s < n; ++s) {
            if (r == s) {
                (*B)[r][s] = 0; // Execute assignment only on diagonal elements
                continue;
            }
            (*B)[r][s] = 0; // Redundant assignment, kept for consistent behavior
        }
}
