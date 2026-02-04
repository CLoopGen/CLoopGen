#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — traverse arrays from end to beginning
    for (n = 15; n != (size_t)-1; --n) {
        out[n] = in[n] ^ iv[n];
    }
}
