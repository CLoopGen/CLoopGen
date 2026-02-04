#include <stdio.h>

#include <inttypes.h>

extern int n;
extern short *data;
extern unsigned char *converted;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = n - 1; i >= 0; i--) {
        converted[i] = (data[i] - 32768) / 256;
    }
}
