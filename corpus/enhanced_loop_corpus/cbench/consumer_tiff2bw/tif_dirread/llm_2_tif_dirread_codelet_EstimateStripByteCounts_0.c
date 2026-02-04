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
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    for (n = 0; n < dircount; n++) {
        TIFFDirEntry entry = dir[n];
        uint32 cc = entry.tdir_count * tiffDataWidth[entry.tdir_type];
        if (cc > sizeof(uint32))
            space += cc;
    }
}
