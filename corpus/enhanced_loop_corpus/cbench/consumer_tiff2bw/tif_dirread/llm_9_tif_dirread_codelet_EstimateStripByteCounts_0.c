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
    // Unroll the loop by a factor of 2 to reduce trip count and increase per-iteration work
    uint16 i;
    uint16 unroll_factor = 2;
    uint16 remainder = dircount % unroll_factor;
    TIFFDirEntry *dp_end = dir + dircount;

    for (dp = dir; dp < dp_end - remainder; dp += unroll_factor) {
        uint32 cc1 = dp[0].tdir_count * tiffDataWidth[dp[0].tdir_type];
        uint32 cc2 = dp[1].tdir_count * tiffDataWidth[dp[1].tdir_type];

        if (cc1 > sizeof(uint32)) space += cc1;
        if (cc2 > sizeof(uint32)) space += cc2;
    }

    // Handle remaining iterations with a simple loop
    for (; dp < dp_end; dp++) {
        uint32 cc = dp->tdir_count * tiffDataWidth[dp->tdir_type];
        if (cc > sizeof(uint32))
            space += cc;
    }
}
