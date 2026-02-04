#include <stdio.h>

#include <inttypes.h>

typedef double NV;

extern int freq[200];
extern int i;
extern int max;
extern NV sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (i = max; i > 0; i -= 2) {
        sum += freq[i] * i * i;
        if (i == 1) break; // Prevent underflow when i becomes 1 and we subtract 2
        sum += freq[i-1] * (i-1) * (i-1);
    }
}
