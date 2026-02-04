#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 12 - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            int idx = i / 2;
            raxKey[idx] = (unsigned char)(bucketKey & 255);
            bucketKey >>= 8;
        }
    }
}
