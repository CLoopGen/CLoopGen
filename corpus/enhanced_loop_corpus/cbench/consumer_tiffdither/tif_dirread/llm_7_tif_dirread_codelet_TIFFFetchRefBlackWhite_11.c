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
    uint32 *data = (uint32 *)cp;
    float *dest = fp;
    for (i = 0; i < dir->tdir_count; i++) {
        dest[i] = (float)data[i];
        data[i] = 0; // Introduce WAW dependency by writing back to data (loop-carried via memory side effect)
    }
}
