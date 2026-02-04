#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (factor of 2)
    // This variant assumes inc2 is 1 and unrolls the loop to check two elements consecutively
    // to exploit spatial locality and reduce branch frequency.
    int temp_len = len;
    unsigned char *temp_s2 = s2;
    int step = 1;  // Assuming inc2 == 1 for consecutive access

    for (; temp_len >= 2 && temp_s2[0] == xor && temp_s2[step] == xor; 
         temp_s2 += 2 * step, temp_len -= 2)
        continue;

    // Handle leftover element
    if (temp_len > 0 && *temp_s2 == xor) {
        temp_s2 += step;
        temp_len--;
    }

    // Update original variables if needed (side-effect simulation)
    s2 = temp_s2;
    len = temp_len;
}
