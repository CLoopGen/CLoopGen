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
    uint32 count = dir->tdir_count;
    for (i = 0; i < count; i += 2) {
        if (i + 1 < count) {
            fp[i]     = (float)((uint32 *)cp)[i];
            fp[i + 1] = (float)((uint32 *)cp)[i + 1];
        } else {
            fp[i] = (float)((uint32 *)cp)[i];
        }
    }
}
