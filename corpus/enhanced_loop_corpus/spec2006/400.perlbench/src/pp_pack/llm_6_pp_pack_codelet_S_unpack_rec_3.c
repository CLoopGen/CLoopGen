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



void loop() {
    I32 local_bits;
    for (len = 0; len < aint; len++) {
        if (len & 1) {
            bits >>= 4;
            local_bits = bits;
        } else {
            local_bits = *s++;
        }
        *str++ = PL_hexdigit[local_bits & 15];
    }
}
