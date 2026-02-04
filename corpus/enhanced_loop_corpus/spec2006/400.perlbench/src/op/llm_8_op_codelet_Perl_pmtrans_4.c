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
for (i = 0; i < 256; i += 4) {
    if (!tbl[i]) {
        if (j >= (I32)rlen) {
            if (del) {
                tbl[i] = -2;
                tbl[i+1] = -2;
                tbl[i+2] = -2;
                tbl[i+3] = -2;
            } else if (rlen) {
                I32 val = r[j - 1];
                tbl[i] = val;
                tbl[i+1] = val;
                tbl[i+2] = val;
                tbl[i+3] = val;
            } else {
                tbl[i] = (short)i;
                tbl[i+1] = (short)(i+1);
                tbl[i+2] = (short)(i+2);
                tbl[i+3] = (short)(i+3);
            }
        } else {
            if (i < 128 && r[j] >= 128)
                grows = 1;
            tbl[i] = r[j++];
            if (j < (I32)rlen) tbl[i+1] = r[j++];
            else if (!del && rlen) tbl[i+1] = r[j-2];
            else tbl[i+1] = del ? -2 : (short)(i+1);

            if (j < (I32)rlen) tbl[i+2] = r[j++];
            else if (!del && rlen) tbl[i+2] = r[(j-3) < 0 ? 0 : j-3];
            else tbl[i+2] = del ? -2 : (short)(i+2);

            if (j < (I32)rlen) tbl[i+3] = r[j++];
            else if (!del && rlen) tbl[i+3] = r[(j-4) < 0 ? 0 : j-4];
            else tbl[i+3] = del ? -2 : (short)(i+3);
        }
    } else if (!tbl[i+1] && i+1 < 256) {
        tbl[i+1] = (short)(i+1);
    }
}
}
