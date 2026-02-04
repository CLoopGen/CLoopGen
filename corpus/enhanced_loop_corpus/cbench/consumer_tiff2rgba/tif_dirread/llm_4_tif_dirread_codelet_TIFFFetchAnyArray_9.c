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
    for (i = dir->tdir_count - 1; i >= 0; i--) {
        if (v + i != NULL && vp + i != NULL)
            v[i] = vp[i];
    }
}
