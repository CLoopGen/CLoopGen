#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step of 2 (write every other location)
    // Simulate a strided access pattern by incrementing pointer by 2 each time
    unsigned short *temp_p = p;
    for (i = 2; i < (6 + 3); i++) {
        *temp_p = 0;
        temp_p += 2;  // Stride of 2 in memory access
    }
    p = temp_p;  // Update original pointer to reflect final position
}
