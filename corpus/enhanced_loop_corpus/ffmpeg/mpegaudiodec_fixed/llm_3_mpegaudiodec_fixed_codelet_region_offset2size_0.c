#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GranuleDef {
    uint8_t scfsi;
    int part2_3_length;
    int big_values;
    int global_gain;
    int scalefac_compress;
    uint8_t block_type;
    uint8_t switch_point;
    int table_select[3];
    int subblock_gain[3];
    uint8_t scalefac_scale;
    uint8_t count1table_select;
    int region_size[3];
    int preflag;
    int short_start;
    int long_end;
    uint8_t scale_factors[40];
    int sb_hybrid[576] __attribute__((aligned(16)));
} GranuleDef;

extern GranuleDef *g;
extern int i;
extern int k;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access via pointer arithmetic on a simulated array of GranuleDef (though single instance)
    // Simulate accessing fields with explicit byte offsets to modify access pattern
    volatile uint8_t* base = (volatile uint8_t*)g;
    int* region_ptr = (int*)(base + offsetof(GranuleDef, region_size));
    int big_vals = g->big_values;
    
    int temp_j = j;
    for (i = 0; i < 3; i++) {
        int region_val = *(region_ptr + i);
        k = (region_val > big_vals) ? big_vals : region_val;
        *(region_ptr + i) = k - temp_j;
        temp_j = k;
    }
}
