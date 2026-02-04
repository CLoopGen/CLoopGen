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
    // Unrolled by 2x to reduce trip count and increase per-iteration operations
    uint16 step = 2;
    uint16 remainder = dircount % 2;
    uint16 iter = (dircount + 1) / 2; // Adjust iteration count for unrolling

    dp = dir;
    for (n = iter; n > 0; n--) {
        uint32 cc1 = dp[0].tdir_count * tiffDataWidth[dp[0].tdir_type];
        if (cc1 > sizeof(uint32))
            space += cc1;

        if (n == 1 && remainder == 1) {
            // Only one element left after unrolling
            break;
        }

        uint32 cc2 = dp[1].tdir_count * tiffDataWidth[dp[1].tdir_type];
        if (cc2 > sizeof(uint32))
            space += cc2;

        dp += step;
    }
}
