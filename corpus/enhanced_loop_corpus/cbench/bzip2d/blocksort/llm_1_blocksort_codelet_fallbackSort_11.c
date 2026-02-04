#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *fmap;
extern UInt32 *eclass;
extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 H;
extern Int32 i;
extern Int32 j;
extern Int32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nblock > 0) {
        i = 0;
        for (; i < nblock; ) {
            if ((bhtab[(i) >> 5] & (1 << ((i) & 31))))
                j = i;
            k = fmap[i] - H;
            if (k < 0)
                k += nblock;
            eclass[k] = j;
            i++;
            // Further nested logic in a controlled manner
            for (Int32 step = 0; i < nblock && step < 4; step++, i++) {
                if ((bhtab[(i) >> 5] & (1 << ((i) & 31))))
                    j = i;
                k = fmap[i] - H;
                if (k < 0)
                    k += nblock;
                eclass[k] = j;
            }
        }
    }
}
