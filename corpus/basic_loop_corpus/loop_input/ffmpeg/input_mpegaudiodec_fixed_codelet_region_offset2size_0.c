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

GranuleDef *g;
int i;
int k;
int j;

void init_vars() {
    g = (GranuleDef*)aligned_alloc(16, sizeof(GranuleDef));
    
    // Initialize region_size and big_values to ensure safe loop operation
    g->big_values = 300;
    g->region_size[0] = 100;
    g->region_size[1] = 200;
    g->region_size[2] = 300;
    
    // Initialize j to a reasonable starting value within bounds
    j = 50;
    
    // Initialize other fields to avoid undefined behavior if accessed elsewhere
    g->scfsi = 0;
    g->part2_3_length = 0;
    g->global_gain = 0;
    g->scalefac_compress = 0;
    g->block_type = 0;
    g->switch_point = 0;
    g->table_select[0] = 0; g->table_select[1] = 0; g->table_select[2] = 0;
    g->subblock_gain[0] = 0; g->subblock_gain[1] = 0; g->subblock_gain[2] = 0;
    g->scalefac_scale = 0;
    g->count1table_select = 0;
    g->preflag = 0;
    g->short_start = 0;
    g->long_end = 0;
    
    for (int idx = 0; idx < 40; idx++) {
        g->scale_factors[idx] = 0;
    }
    
    for (int idx = 0; idx < 576; idx++) {
        g->sb_hybrid[idx] = 0;
    }
}