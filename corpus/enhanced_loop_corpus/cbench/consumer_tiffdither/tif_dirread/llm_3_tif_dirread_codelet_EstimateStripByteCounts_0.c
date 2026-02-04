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
    // Variant 2: Indirect array access using an index map (simulating non-contiguous or reordered processing)
    // Assume we process entries in reverse order (indirect access via reversed indices)
    uint16 i;
    for (i = 0; i < dircount; i++) {
        TIFFDirEntry *dp = &dir[dircount - 1 - i]; // Reverse traversal (indirect pattern)
        uint32 cc = dp->tdir_count * tiffDataWidth[dp->tdir_type];
        if (cc > sizeof(uint32))
            space += cc;
    }
}
