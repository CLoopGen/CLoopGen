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
    for (i = 0; i < 256; i++) {
        for (j = ((i == 0) ? 0 : j); !tbl[i] && j < (I32)rlen + (del || !rlen); ) {
            if (j >= (I32)rlen) {
                if (del)
                    tbl[i] = -2;
                else if (rlen)
                    tbl[i] = r[j - 1];
                else
                    tbl[i] = (short)i;
            } else {
                if (i < 128 && r[j] >= 128)
                    grows = 1;
                tbl[i] = r[j++];
            }
            break;
        }
    }
}
