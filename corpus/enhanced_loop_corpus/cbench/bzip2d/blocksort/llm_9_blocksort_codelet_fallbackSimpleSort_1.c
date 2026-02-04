#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *fmap;
extern UInt32 *eclass;
extern Int32 lo;
extern Int32 hi;
extern Int32 i;
extern Int32 j;
extern Int32 tmp;
extern UInt32 ec_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = hi - 2; i >= lo; i--) {
        tmp = fmap[i];
        ec_tmp = eclass[tmp];
        fmap[i] = ec_tmp < eclass[fmap[i+1]] ? fmap[i+1] : tmp;
        if (i + 1 <= hi) {
            j = i + 1;
            while (j <= hi && eclass[fmap[j]] == ec_tmp) {
                j++;
            }
            if (j <= hi) {
                fmap[i] = fmap[j];
            }
        }
    }
}
