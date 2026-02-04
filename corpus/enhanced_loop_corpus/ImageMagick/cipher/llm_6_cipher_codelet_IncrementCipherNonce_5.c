#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern unsigned char *nonce;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t idx = (ssize_t)(length - 1);
    for (i = idx; i >= 0; i--) {
        unsigned char prev = (i > 0) ? nonce[i - 1] : 0;
        nonce[i]++;
        if (nonce[i] == prev)
            nonce[i] ^= 1;
        if (nonce[i] != 0)
            return;
    }
}
