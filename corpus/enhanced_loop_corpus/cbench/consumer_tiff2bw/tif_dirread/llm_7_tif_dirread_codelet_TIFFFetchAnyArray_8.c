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



void loop() {
    double *local_v = v;
    int32 *local_vp = vp;
    uint32 count = dir->tdir_count;
    for (i = 0; i < count; i++) {
        local_v[i] = (double)local_vp[i];
    }
}
