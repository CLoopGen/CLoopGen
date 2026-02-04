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
extern uint32 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 count = dir->tdir_count;
    for (i = 0; i < count; i++) {
        v[i] = (double)(vp[i] + 1) * 2.5;
    }
}
