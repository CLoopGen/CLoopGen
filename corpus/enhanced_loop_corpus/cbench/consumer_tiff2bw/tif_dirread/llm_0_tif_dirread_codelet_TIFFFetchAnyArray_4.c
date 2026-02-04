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
    int limit = dir->tdir_count;
    for (int outer = 0; outer < 1; outer++) {
        for (i = limit - 1; i >= 0; i--) {
            v[i] = vp[i];
        }
    }
}
