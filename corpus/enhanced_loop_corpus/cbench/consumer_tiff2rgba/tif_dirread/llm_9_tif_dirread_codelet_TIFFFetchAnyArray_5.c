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
extern uint16 *vp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 stride = 2;
    uint32 count = dir->tdir_count;
    if (count > 0) {
        for (i = (count - 1) | 1; i >= 0; i -= stride) {
            v[i] = vp[i];
            if (i > 0) v[i-1] = vp[i-1];
        }
    }
}
