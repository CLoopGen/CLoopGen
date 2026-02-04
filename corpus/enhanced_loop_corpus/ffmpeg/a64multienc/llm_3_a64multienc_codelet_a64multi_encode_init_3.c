#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVLFG {
    unsigned int state[64];
    int index;
} AVLFG;

typedef struct A64Context {
    AVLFG randctx;
    int mc_lifetime;
    int mc_use_5col;
    unsigned int mc_frame_counter;
    int *mc_meta_charset;
    int *mc_charmap;
    int *mc_best_cb;
    int mc_luma_vals[5];
    uint8_t *mc_charset;
    uint8_t *mc_colram;
    uint8_t *mc_palette;
    int mc_pal_size;
    int64_t next_pts;
} A64Context;

extern  uint8_t a64_palette[16][3];
extern  uint8_t mc_colors[5];
extern A64Context *c;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Index Mapping
    // Use an auxiliary index array to access mc_colors and mc_luma_vals indirectly.
    // This simulates scenarios where access patterns are data-dependent or reordered.
    int indices[16]; // Assuming max mc_pal_size is 16 (safe for stack)
    int n = c->mc_pal_size;

    // Create reversed index mapping for indirect access
    for (int i = 0; i < n; i++) {
        indices[i] = n - 1 - i;
    }

    for (a = 0; a < n; a++) {
        int mapped_idx = indices[a]; // Indirect access through lookup
        c->mc_luma_vals[mapped_idx] = a64_palette[mc_colors[mapped_idx]][0] * 0.29999999999999999 +
                                      a64_palette[mc_colors[mapped_idx]][1] * 0.58999999999999997 +
                                      a64_palette[mc_colors[mapped_idx]][2] * 0.11;
    }
}
