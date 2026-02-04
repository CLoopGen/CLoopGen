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
    // Variant 2: Strided memory access — process every second element forward, then second pass for odd indices
    // This creates a strided pattern with stride 2
    uint16 step = 2;
    uint16 passes = 2;
    space = 0; // Reset space to ensure deterministic behavior across runs
    for (uint16 pass = 0; pass < passes; pass++) {
        for (n = dircount; n > 0; n -= step) {
            uint16 idx = (n - 1) - pass; // Adjust index based on pass (0 or 1)
            if (idx >= dircount) continue;
            dp = &dir[idx];
            uint32 cc = dp->tdir_count * tiffDataWidth[dp->tdir_type];
            if (cc > sizeof(uint32))
                space += cc;
        }
    }
}
