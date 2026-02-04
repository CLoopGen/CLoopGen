#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint16_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int shift = (9 + 1) / 2;
    int tile_size = 1 << shift;
    int radius_plus_one = radiusV + 1;
    for (int i = 0; i < width; i++) {
        int fine_index = tile_size * (width * (srcp[i] >> shift) + i) + (srcp[i] & (tile_size - 1));
        int coarse_index = tile_size * i + (srcp[i] >> shift);
        // Introduce temporary accumulators to remove immediate write-write and read-after-write dependencies
        // This creates local data reuse and reduces memory dependency chains
        uint16_t temp_fine = cfine[fine_index];
        uint16_t temp_coarse = ccoarse[coarse_index];
        temp_fine += radius_plus_one;
        temp_coarse += radius_plus_one;
        cfine[fine_index] = temp_fine;
        ccoarse[coarse_index] = temp_coarse;
    }
}
