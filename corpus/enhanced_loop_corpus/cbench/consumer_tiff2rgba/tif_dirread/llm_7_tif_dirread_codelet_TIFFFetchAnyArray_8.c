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
    int32 count = dir->tdir_count;
    for (i = count - 1; i >= 0; i -= 2) {
        if (i == 0) {
            v[0] = vp[0];
        } else {
            v[i] = vp[i];
            v[i-1] = vp[i-1];
        }
    }
}
