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
    float scale = 1.5f;
    float offset = 0.5f;
    for (i = 0; i < count; i++) {
        uint32 val = ((uint32 *)cp)[i];
        fp[i] = (float)(val * scale + offset);
    }
}
