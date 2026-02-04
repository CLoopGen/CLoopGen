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
    uint32 limit = (dir->tdir_count + 1) & ~1u; // Round up to even
    for (i = 0; i < limit; i += step) {
        v[i] = vp[i];
        if (i + 1 < dir->tdir_count)
            v[i + 1] = vp[i + 1];
    }
}
