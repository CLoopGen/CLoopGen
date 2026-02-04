#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN rlen;
extern U8 *r;
extern I32 i;
extern I32 j;
extern I32 del;
extern I32 grows;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_j = 0;
    short local_tbl[256];
    
    for (i = 0; i < 256; i++) {
        local_tbl[i] = tbl[i];
    }

    for (i = 0; i < 256; i++) {
        if (!local_tbl[i]) {
            if (local_j >= (I32)rlen) {
                if (del)
                    local_tbl[i] = -2;
                else if (rlen)
                    local_tbl[i] = r[local_j - 1];
                else
                    local_tbl[i] = (short)i;
            } else {
                if (i < 128 && r[local_j] >= 128)
                    grows = 1;
                local_tbl[i] = r[local_j++];
            }
        }
    }

    for (i = 0; i < 256; i++) {
        tbl[i] = local_tbl[i];
    }
}
