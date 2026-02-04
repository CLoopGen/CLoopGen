#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int deltai[8];
extern int deltaj[8];
extern int delta[8];
extern Intersection board[421];
extern  int permeability_array[400];
extern  char safe[400];
extern int ii;
extern int queue[400];
extern int d;
extern int b;
extern int queue_start;
extern int queue_end;
extern int working[400];
extern int current_strength;
extern int delta_i;
extern int delta_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access pattern: process deltas in reverse and use indirect indexing via precomputed offsets
    int reversed_indices[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (; d < 8; d++) {
        int rev_d = reversed_indices[d];  // Indirect access to delta directions
        int base_offset = ii + delta[rev_d];
        
        if (board[base_offset] == 3) continue;

        int is_safe = safe[base_offset];
        int di = deltai[rev_d];
        int dj = deltaj[rev_d];
        int directional_alignment = di * delta_i + dj * delta_j;

        if (!is_safe && (directional_alignment > 0 || queue_start == 1)) {
            int contribution;
            int perm_here = permeability_array[ii];

            // Strided access: instead of conditional ternary, unconditionally compute both axes
            int stride_offset_i = di * (19 + 1);
            int stride_offset_j = dj;
            int perm_i = permeability_array[ii + stride_offset_i];
            int perm_j = permeability_array[ii + stride_offset_j];
            int max_perm = perm_i;
            if (perm_j > perm_i) max_perm = perm_j;

            int scaled_perm = (perm_here * max_perm) >> 12;
            if (scaled_perm == 0) continue;

            contribution = (current_strength * scaled_perm) >> 12;

            if (queue_start != 1) {
                contribution *= (directional_alignment * directional_alignment);
                contribution = (b * contribution) >> 12;
            }

            int threshold = (int)(0.02 * (1 << 12) + 0.5);
            if (contribution <= threshold) continue;

            if (working[base_offset] == 0) {
                queue[queue_end] = base_offset;
                queue_end++;
            }
            working[base_offset] += contribution;
        }
    }
}
