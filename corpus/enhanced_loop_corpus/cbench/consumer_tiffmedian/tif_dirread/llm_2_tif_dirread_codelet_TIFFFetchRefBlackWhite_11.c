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
    // Variant 1: Strided memory access with stride of 2
    uint32 count = dir->tdir_count;
    uint32 *cp_uint32 = (uint32 *)cp;
    for (i = 0; i < count; i += 2) {
        if (i < count) fp[i] = (float)cp_uint32[i];
    }
    // Handle odd-sized arrays by filling last element if count is odd
    if (count % 2 == 1) {
        fp[count - 1] = (float)cp_uint32[count - 1];
    }
}
