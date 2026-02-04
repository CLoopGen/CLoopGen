#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    l = (unsigned int)(len - plen - 1);
    for (; plen < len; plen++) {
        if (l > 0) {
            out[plen] = l--;
        } else {
            out[plen] = 0;
            break;
        }
    }
}
