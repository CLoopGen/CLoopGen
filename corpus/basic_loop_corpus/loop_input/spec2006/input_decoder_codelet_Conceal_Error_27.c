#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short **inY;
unsigned short ***refY;
int i;
int j;
int ref_inx;
int pos_y;
int pos_x;

#define DATA_SIZE_MB 64
#define ARRAY_DIM (1024 * 16) // Adjust to control total data size

static unsigned short *flat_inY_data;
static unsigned short *flat_refY_data;
static unsigned short **inY_rows;
static unsigned short ***refY_frames;

void init_vars() {
    const int dim = ARRAY_DIM;
    ref_inx = 0;
    pos_y = 0;
    pos_x = 0;

    // Ensure the loop bounds (pos_y + 15, pos_x + 15) are within array bounds
    if (dim <= pos_y + 16 || dim <= pos_x + 16) {
        // Adjust dim to be large enough
        // Recompute based on desired memory footprint
        // Target ~64MB of data: we have two 3D-like arrays (refY and inY as 2D view)
        // Let's use dim such that dim*dim*sizeof(short)*2 ≈ 64MB
        // So dim^2 ≈ 32M => dim ≈ sqrt(32M) ≈ 5660
        // Use 8k for clean alignment
        // But we need to allocate carefully
    }

    // Recalculate dim for ~64MB total data
    // We have:
    //   inY: dim x dim -> dim² elements
    //   refY: 1 frame x dim x dim -> dim² elements
    // Total: 2 * dim² * sizeof(short) = 2 * dim² * 2 = 4 * dim² bytes
    // For 64MB: 4 * dim² = 64 * 1024 * 1024 => dim² = 16 * 1024 * 1024 => dim = 4096
    const int target_dim = 4096;
    const int frame_count = 1; // Only using ref_inx=0

    flat_inY_data = (unsigned short*)calloc(target_dim * target_dim, sizeof(unsigned short));
    flat_refY_data = (unsigned short*)calloc(target_dim * target_dim, sizeof(unsigned short));

    inY_rows = (unsigned short**)malloc(target_dim * sizeof(unsigned short*));
    refY_frames = (unsigned short***)malloc(frame_count * sizeof(unsigned short**));
    for (int y = 0; y < target_dim; y++) {
        inY_rows[y] = &flat_inY_data[y * target_dim];
    }
    refY_frames[0] = (unsigned short**)malloc(target_dim * sizeof(unsigned short*));
    for (int y = 0; y < target_dim; y++) {
        refY_frames[0][y] = &flat_refY_data[y * target_dim];
    }

    inY = inY_rows;
    refY = refY_frames;

    // Set position so that pos_y+15 and pos_x+15 are valid
    pos_y = 100;
    pos_x = 100;
}