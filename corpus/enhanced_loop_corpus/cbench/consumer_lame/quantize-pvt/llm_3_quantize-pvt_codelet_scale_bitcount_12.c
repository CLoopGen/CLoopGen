#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

extern int pretab[21];
extern III_scalefac_t *scalefac;
extern int sfb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use a predefined index array to access elements in a non-sequential order
    // Simulates indirect or gather-style access pattern
    int indices[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11}; // Reverse order
    for (int i = 0; i < 10; i++) {
        int sfb = indices[i];
        scalefac->l[sfb] -= pretab[sfb];
    }
}
