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
extern uint16 dircount;
extern TIFFDirEntry *dp;
extern uint32 space;
extern uint16 n;
extern const int tiffDataWidth[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dp = dir, n = dircount; n > 0; n--, dp++) {
        uint32 element_size = tiffDataWidth[dp->tdir_type];
        uint32 cc = dp->tdir_count * element_size;
        if (cc > sizeof(uint32)) {
            space += cc + element_size;  // Additional arithmetic: increase computational intensity
        }
    }
}
