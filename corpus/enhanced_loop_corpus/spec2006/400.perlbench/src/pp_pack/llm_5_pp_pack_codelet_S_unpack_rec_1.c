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
    for (len = 0; len < aint; len++) {
        if (len >= aint) continue;
        if (len & 7) {
            bits >>= 1;
        } else {
            bits = *s++;
        }
        char bit_char = '0' + (bits & 1);
        *str++ = bit_char;
    }
}
