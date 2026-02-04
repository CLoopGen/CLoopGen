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
extern char *cp;
extern float *fp;
extern uint32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 limit = dir->tdir_count * 2;
    for (i = 0; i < limit; i += 2) {
        uint32 val = ((uint32 *)cp)[i >> 1];
        fp[i >> 1] = (float)(val + (val >> 8));
    }
}
