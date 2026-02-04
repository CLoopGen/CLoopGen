#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int coord;
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing p1 and coordinates with strided access (every 2 bytes),
    // we reorganize the data access to be more sequential by pre-loading values into local arrays.
    uint16_t local_p1[width];
    uint16_t local_coords[8][width];

    // Pre-load p1 as consecutive uint16_t values
    for (x = 0; x < width; x++) {
        local_p1[x] = ((const av_alias16 *)(&p1[2 * x]))->u16;
    }

    // Pre-load coordinate planes for better spatial locality
    for (i = 0; i < 8; i++) {
        if (coord & (1 << i)) {
            for (x = 0; x < width; x++) {
                local_coords[i][x] = ((const av_alias16 *)(coordinates[i] + x * 2))->u16;
            }
        }
    }

    for (x = 0; x < width; x++) {
        int min = local_p1[x];
        int limit = (min - threshold > 0) ? min - threshold : 0;

        for (i = 0; i < 8; i++) {
            if (coord & (1 << i)) {
                if (local_coords[i][x] < min) {
                    min = local_coords[i][x];
                }
            }
            if (limit > min) {
                min = limit;
            }
        }
        dst[x] = min;
    }
}
