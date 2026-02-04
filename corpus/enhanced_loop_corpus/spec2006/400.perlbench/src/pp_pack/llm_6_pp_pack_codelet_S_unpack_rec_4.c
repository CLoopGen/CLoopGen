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
    I32 local_bits = 0;
    for (len = 0; len < aint; len++) {
        if (len & 1) {
            local_bits <<= 4;
        } else {
            local_bits = s[len >> 1]; // Eliminate pointer side effect, use direct indexing
        }
        str[len] = PL_hexdigit[(local_bits >> 4) & 15]; // Remove pointer arithmetic, use indexed store
    }
}
