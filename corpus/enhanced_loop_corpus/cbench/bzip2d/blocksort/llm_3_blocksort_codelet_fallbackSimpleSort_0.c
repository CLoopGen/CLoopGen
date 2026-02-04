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
UInt32 *fmap_ptr = &fmap[lo];
UInt32 *eclass_base = eclass;
Int32 range = hi - lo + 1;
for (i = range - 1; i >= 0; i--) {
    tmp = fmap_ptr[i];
    ec_tmp = eclass_base[tmp];
    Int32 insert_pos = i;
    for (j = i + 1; j < range && ec_tmp > eclass_base[fmap_ptr[j]]; j++) {
        fmap_ptr[j - 1] = fmap_ptr[j];
        insert_pos = j;
    }
    fmap_ptr[insert_pos - 1] = tmp;
}
}
