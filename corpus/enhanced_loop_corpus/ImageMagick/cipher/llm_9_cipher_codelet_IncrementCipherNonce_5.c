#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern unsigned char *nonce;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (ssize_t)(length - 1); i >= 0 && i >= (ssize_t)(length - 8); i--) {
        nonce[i] += 2;
        nonce[i] = (nonce[i] == 0) ? 1 : nonce[i];
        if (nonce[i] > 1)
            return;
    }
}
