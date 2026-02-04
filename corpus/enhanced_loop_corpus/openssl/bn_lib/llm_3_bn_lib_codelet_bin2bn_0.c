#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride (double the original step)
    // Simulates a more sparse memory access pattern by skipping every other element
    // in the original sequence, effectively doubling the stride.
    int temp_len = len;
    unsigned char *temp_s2 = s2;
    int effective_inc = inc2 * 2;  // Double strided access

    for (; temp_len > 1 && *temp_s2 == xor; 
         temp_s2 += effective_inc, temp_len -= 2)
        continue;

    // Final single-element check if remaining length is at least 1
    if (temp_len > 0 && *temp_s2 == xor) {
        temp_s2 += inc2;
        temp_len--;
    }

    // Sync back to original state
    s2 = temp_s2;
    len = temp_len;
}
