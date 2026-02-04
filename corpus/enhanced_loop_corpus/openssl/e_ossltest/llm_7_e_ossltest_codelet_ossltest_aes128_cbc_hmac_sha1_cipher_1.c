#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t len;
extern unsigned int l;
extern size_t plen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    l = (unsigned int)(len - plen - 1);
    for (size_t i = 0; i < len - plen; i++) {
        out[plen + i] = l; // Remove loop-carried dependency by using induction variable `i`; `l` is invariant
    }
    plen = len; // Update plen after loop to maintain semantic equivalence
}
