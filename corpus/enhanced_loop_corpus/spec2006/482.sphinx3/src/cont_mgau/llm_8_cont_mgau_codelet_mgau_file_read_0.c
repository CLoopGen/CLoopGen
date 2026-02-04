#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 i;
extern int32 n_feat;
extern int32 *veclen;
extern int32 blk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, blk = 0; i < n_feat; i += 2) {
        if (i + 1 < n_feat) {
            blk += veclen[i] + veclen[i + 1];
        } else {
            blk += veclen[i];
        }
    }
}
