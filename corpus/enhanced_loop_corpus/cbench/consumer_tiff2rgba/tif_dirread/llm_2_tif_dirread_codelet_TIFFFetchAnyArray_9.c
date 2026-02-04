#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

typedef unsigned int uint32;

typedef struct {
    uint16 tdir_tag;
    uint16 tdir_type;
    uint32 tdir_count;
    uint32 tdir_offset;
} TIFFDirEntry;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern float *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    int count = dir->tdir_count;
    for (i = (count & ~1) - 1; i >= 1; i -= 2) {
        v[i]     = vp[i];
        v[i - 1] = vp[i - 1];
    }
    // Handle remaining element if count is odd
    if (count & 1)
        v[0] = vp[0];
}
