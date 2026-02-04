#include <stdio.h>

#include <inttypes.h>

extern unsigned short c[];
extern unsigned short p[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW and RAW dependencies with loop-carried dependence
    // We introduce a loop-carried dependency by making c[i] depend on c[i-1]
    // Also create WAW by writing to p[i] after c[i], and RAW by using updated c[i] in next iteration
    for (i = 2; i < (6 + 3); i++) {
        c[i] = p[i];
        if (i > 2) {
            c[i] += c[i-1];  // Loop-carried RAW and WAW on c[i]
        }
        p[i] = c[i] + 1;     // WAW on p[i], though p is extern, we assume it's safe to write
    }
}
