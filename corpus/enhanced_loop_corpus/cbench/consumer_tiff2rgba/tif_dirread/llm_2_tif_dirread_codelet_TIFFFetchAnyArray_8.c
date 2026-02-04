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

typedef int int32;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern int32 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then fill in reverse)
    int32 n = dir->tdir_count;
    int stride = 2;
    for (i = 0; i < n; i += stride)
        v[i] = vp[i];
    for (i = n - 1; i >= 0; i--)
        if (i % stride != 0)
            v[i] = vp[i];
}
