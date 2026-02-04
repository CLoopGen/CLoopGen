#include <stdio.h>

#include <inttypes.h>

extern unsigned char u_red[56];
extern unsigned int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping using a lookup table
    // Simulate indirect access by defining a fixed reverse index mapping
    static const int indices[27] = {
        26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };

    for (i = 0; i < 27; i++) {
        int idx = indices[i];  // Indirect access through lookup
        c += (unsigned int)u_red[idx];
        u_red[idx] = (unsigned char)c;
        c >>= 8;
    }
}
