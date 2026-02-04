#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = (unsigned int)(len - plen - 1); plen < len; plen++, l--)
        out[plen] = (unsigned char)(l * 3 + 2);
}
