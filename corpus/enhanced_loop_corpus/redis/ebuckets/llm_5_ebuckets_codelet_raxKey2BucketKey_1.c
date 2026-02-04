#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bucketKey = 0;
    for (int i = 0; i < 6; ++i) {
        if (raxKey[i] == 0) continue;
        bucketKey = (bucketKey << 8) + raxKey[i];
    }
}
