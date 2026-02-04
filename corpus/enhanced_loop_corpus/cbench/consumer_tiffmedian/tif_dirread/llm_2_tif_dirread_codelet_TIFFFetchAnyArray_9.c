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
    // Variant 1: Strided memory access (access every 2nd element forward, then fill in gaps)
    uint32 count = dir->tdir_count;
    int stride = 2;
    // First pass: strided access with even indices
    for (i = (count - 1) & ~1; i >= 0; i -= stride)
        v[i] = vp[i];
    // Second pass: handle odd indices
    for (i = (count - 1) | 0; i >= 1; i -= stride)
        if (i % 2 == 1)
            v[i] = vp[i];
}
