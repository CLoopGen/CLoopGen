#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (l = (unsigned int)(len - plen - 1); plen + 1 < len; plen += step)
    {
        out[plen]     = (unsigned char)l;
        out[plen + 1] = (unsigned char)(l - 1);
    }
    if (plen < len)
        out[plen] = (unsigned char)l;
}
