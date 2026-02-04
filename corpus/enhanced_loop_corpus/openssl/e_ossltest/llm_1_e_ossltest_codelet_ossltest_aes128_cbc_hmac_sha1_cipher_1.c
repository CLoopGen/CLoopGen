#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (plen < len) {
        l = (unsigned int)(len - plen - 1);
        for (size_t i = plen; i < len; i++) {
            out[i] = l;
        }
    }
}
