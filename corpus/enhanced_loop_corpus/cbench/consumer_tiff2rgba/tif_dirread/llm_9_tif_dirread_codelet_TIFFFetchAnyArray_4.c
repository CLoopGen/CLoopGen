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

typedef short int16;

extern TIFFDirEntry *dir;
extern double *v;
extern int i;
extern int16 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    int limit = dir->tdir_count - (dir->tdir_count % 2);
    for (i = 0; i < limit; i += step) {
        v[i]     = vp[i];
        v[i + 1] = vp[i + 1];
    }
    if (dir->tdir_count % 2) {
        v[dir->tdir_count - 1] = vp[dir->tdir_count - 1];
    }
}
