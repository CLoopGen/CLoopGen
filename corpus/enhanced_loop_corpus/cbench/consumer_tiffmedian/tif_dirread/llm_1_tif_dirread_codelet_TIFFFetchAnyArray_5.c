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
    int limit = dir->tdir_count;
    if (limit > 0) {
        i = limit - 1;
        do {
            v[i] = vp[i];
        } while (i-- > 0);
    }
}
