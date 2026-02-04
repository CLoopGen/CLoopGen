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
    uint32 j;
    for (i = 0; i < dir->tdir_count; i++) {
        for (j = 0; j < 1; j++) {  // Nested loop with fixed bound (depth increased)
            fp[i] = (float)((uint32 *)cp)[i];
        }
    }
}
