#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern unsigned char *nonce;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (ssize_t)(length - 1); i >= 0; i--) {
    for (size_t j = i; j <= i; j++) {
        nonce[j]++;
        if (nonce[j] != 0)
            break;
    }
    if (nonce[i] != 0)
        return;
}
}
