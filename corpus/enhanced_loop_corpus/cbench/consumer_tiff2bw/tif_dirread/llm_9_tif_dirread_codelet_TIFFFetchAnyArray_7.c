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
    for (i = count - 1; i != (uint32)-1; i -= 2) {
        v[i] = vp[i];
        if (i > 0) {
            v[i-1] = vp[i-1];
        }
    }
}
