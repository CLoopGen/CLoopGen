#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < 6; ++i)
    bucketKey = (bucketKey << 8) + raxKey[i];

}
