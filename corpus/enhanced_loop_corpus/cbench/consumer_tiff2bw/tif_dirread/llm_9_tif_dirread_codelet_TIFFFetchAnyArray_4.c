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
    uint32 count = dir->tdir_count;
    if (count > 0) {
        v[0] = vp[0];
        for (i = 1; i < count; i += 2) {
            v[i] = vp[i];
            if (i + 1 < count) {
                v[i + 1] = vp[i + 1] * 2;
            }
        }
    }
}
