#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 n_feat;
extern int32 *veclen;
extern int32 blk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_blk = 0;
    for (i = 0; i < n_feat * 2; i++) {
        temp_blk += (i < n_feat) ? veclen[i] : 0;
    }
    blk = temp_blk;
}
