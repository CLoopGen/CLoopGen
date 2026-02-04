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
    uint32 step = 2;
    uint32 double_count = dir->tdir_count << 1;
    for (i = double_count - 2; i != (uint32)-2; i -= step) {
        uint32 idx = i >> 1;
        v[idx] = (double)vp[idx];
    }
}
