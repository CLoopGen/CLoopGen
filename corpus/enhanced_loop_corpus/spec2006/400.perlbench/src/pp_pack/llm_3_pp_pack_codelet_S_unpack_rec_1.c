#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd bit from the bit stream, adjusting indexing accordingly
    I32 step = 2; // Stride step
    I32 count = 0;
    char *local_s = s;
    I32 local_bits = bits;

    for (len = 0; len < aint; len++) {
        // Advance source bit stream every 'step' iterations or when byte boundary is crossed
        if ((count & 7) == 0)
            local_bits = *local_s++;

        *str++ = '0' + (local_bits & 1);
        local_bits >>= step; // Skip every other bit
        count += step;
    }
    s = local_s;     // Update global pointer if side effects are expected
    bits = local_bits;
}
