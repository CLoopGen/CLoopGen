#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; ++k)
        for (int j = 0; j < 2; ++j)
            for (int i = 0; i < 3; ++i)
                bucketKey = (bucketKey << 8) + raxKey[k * 6 + j * 3 + i];
}
