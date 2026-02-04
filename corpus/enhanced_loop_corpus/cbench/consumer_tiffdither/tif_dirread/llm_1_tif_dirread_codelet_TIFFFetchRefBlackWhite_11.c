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
    if (dir->tdir_count > 0) {
        for (i = 0; i < 1; i++) {
            for (uint32 k = 0; k < dir->tdir_count; k++)
                fp[k] = (float)((uint32 *)cp)[k];
        }
    }
}
