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
    // Variant 1: Consecutive memory access by unrolling the loop with stride of 2
    uint16 i;
    uint16 count = dircount & ~1; // Round down to even number for safe unrolling
    for (i = 0; i < count; i += 2) {
        TIFFDirEntry *dp1 = &dir[i];
        TIFFDirEntry *dp2 = &dir[i + 1];
        uint32 cc1 = dp1->tdir_count * tiffDataWidth[dp1->tdir_type];
        uint32 cc2 = dp2->tdir_count * tiffDataWidth[dp2->tdir_type];
        if (cc1 > sizeof(uint32))
            space += cc1;
        if (cc2 > sizeof(uint32))
            space += cc2;
    }
    // Handle remaining element if dircount is odd
    if ((dircount & 1) && dircount > 0) {
        TIFFDirEntry *dp_last = &dir[dircount - 1];
        uint32 cc = dp_last->tdir_count * tiffDataWidth[dp_last->tdir_type];
        if (cc > sizeof(uint32))
            space += cc;
    }
}
