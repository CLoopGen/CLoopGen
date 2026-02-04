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
    if (dir->tdir_count > 0) {
        i = dir->tdir_count - 1;
        for (; i >= 0; i--) {
            v[i] = vp[i];
        }
    }
}
