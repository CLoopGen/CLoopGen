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
    // Variant 1: Strided memory access (access every 2nd element in reverse, then handle odd indices in a second pass)
    int count = dir->tdir_count;
    for (i = (count - 1) | 1; i >= 0; i -= 2) {
        if (i < count) v[i] = vp[i];
        if (i-1 >= 0) v[i-1] = vp[i-1];
    }
}
