#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = (unsigned int)(len - plen - 1);
    for (l = temp; plen < len; plen++) {
        out[plen] = temp;
        temp = (unsigned int)(len - plen - 1); // Introduce WAW and RAW dependency: temp written and read across iterations
    }
}
