#include <stdio.h>

#include <inttypes.h>

extern int *k2;
extern int *t2;
extern int len2;
extern float id;
extern float tot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len2; i += 2) {
        tot += 1.;
        if (k2[i] == t2[i])
            id += 1.;
        // Handle remaining element if len2 is odd
        if (i + 1 < len2) {
            tot += 1.;
            if (k2[i + 1] == t2[i + 1])
                id += 1.;
        }
    }
}
