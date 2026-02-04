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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to access elements in reverse with step
    uint32 count = dir->tdir_count;
    uint32 aligned_count = count - (count % 2);  // Make it even for safe dual access
    for (i = aligned_count - 2; i >= 0; i -= 2) {
        v[i + 1] = vp[i + 1];
        v[i]     = vp[i];
    }
    // Handle leftover element if count was odd
    if (count % 2) {
        v[0] = vp[0];
    }
}
