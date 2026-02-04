#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int ply;
extern int pv_length[300];
extern move_s pv[300][300];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linear) memory access by flattening the 2D array access
    // Treat the relevant portion as a linear segment for bulk copy
    int start_offset = ply;
    int end_offset = pv_length[ply];
    move_s *src_row = pv[ply];
    move_s *dst_row = pv[ply - 1];

    // Perform consecutive element-wise assignment
    for (int offset = start_offset; offset < end_offset; offset++) {
        dst_row[offset] = src_row[offset];
    }
}
