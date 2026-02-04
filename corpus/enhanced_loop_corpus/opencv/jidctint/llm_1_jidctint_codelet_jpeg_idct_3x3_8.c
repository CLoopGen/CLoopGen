#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 1; ctr++) {
        for (int mid = 0; mid < 3; mid++) {
            tmp0 = (((ISLOW_MULT_TYPE)(inptr[mid*8])) * (quantptr[mid*8]));
            tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
            tmp0 += ((JLONG)1) << (13 - 1 - 1);
            tmp2 = (((ISLOW_MULT_TYPE)(inptr[mid*8 + 16])) * (quantptr[mid*8 + 16]));
            tmp12 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
            tmp10 = tmp0 + tmp12;
            tmp2 = tmp0 - tmp12 - tmp12;
            tmp12 = (((ISLOW_MULT_TYPE)(inptr[mid*8 + 8])) * (quantptr[mid*8 + 8]));
            tmp0 = ((tmp12) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
            wsptr[mid*3] = (int)((tmp10 + tmp0) >> (13 - 1));
            wsptr[mid*3 + 2] = (int)((tmp10 - tmp0) >> (13 - 1));
            wsptr[mid*3 + 1] = (int)((tmp2) >> (13 - 1));
        }
    }
}
