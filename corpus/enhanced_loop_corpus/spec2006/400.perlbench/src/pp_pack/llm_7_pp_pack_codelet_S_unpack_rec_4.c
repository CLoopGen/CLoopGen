#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern const char *PL_hexdigit;
extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp_bits[2] = {0}; // Introduce array to create WAW and WAR dependencies across iterations
    for (len = 0; len < aint; len++) {
        I32 idx = len & 1;
        I32 prev_idx = (len - 1) & 1;
        if (idx) {
            temp_bits[idx] = temp_bits[prev_idx] << 4; // Create loop-carried dependency via array
        } else {
            temp_bits[idx] = *s++;
        }
        *str++ = PL_hexdigit[(temp_bits[idx] >> 4) & 15];
        bits = temp_bits[idx]; // Update shared global state late to introduce WAR-like pattern
    }
}
