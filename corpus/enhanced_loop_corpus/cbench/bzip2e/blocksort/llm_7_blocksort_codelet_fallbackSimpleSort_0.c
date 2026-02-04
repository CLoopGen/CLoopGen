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
    UInt32 *temp_fmap = (UInt32*)__builtin_alloca((hi - lo + 1) * sizeof(UInt32));
    Int32 idx = 0;
    for (i = lo; i <= hi; i++) {
        temp_fmap[idx++] = fmap[i];
    }
    for (i = 0; i < idx; i++) {
        for (j = i + 1; j < idx; j++) {
            if (eclass[temp_fmap[i]] > eclass[temp_fmap[j]]) {
                tmp = temp_fmap[i];
                temp_fmap[i] = temp_fmap[j];
                temp_fmap[j] = tmp;
            }
        }
    }
    for (i = lo; i <= hi; i++) {
        fmap[i] = temp_fmap[i - lo];
    }
}
