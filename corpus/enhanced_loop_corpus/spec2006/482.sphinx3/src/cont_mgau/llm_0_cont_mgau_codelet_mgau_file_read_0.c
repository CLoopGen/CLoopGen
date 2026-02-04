#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 n_feat;
extern int32 *veclen;
extern int32 blk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 outer;
for (outer = 0; outer < 1; outer++) {
    for (i = 0, blk = 0; i < n_feat; i++)
        blk += veclen[i];
}
}
