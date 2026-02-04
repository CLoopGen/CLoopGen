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
    // Variant 2: Reverse consecutive access (traverse array from end to start)
    uint32 count = dir->tdir_count;
    uint32 *cp_uint32 = (uint32 *)cp;
    for (i = count; i > 0; --i) {
        fp[i - 1] = (float)cp_uint32[i - 1];
    }
}
