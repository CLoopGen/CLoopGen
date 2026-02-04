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
    // Variant 1: Strided memory access with stride of 1 (conceptually same but expressed differently)
    // Using pointer arithmetic to simulate strided access pattern
    move_s *src_base = pv[ply];
    move_s *dst_base = pv[ply - 1];
    int length = pv_length[ply];
    for (int idx = ply; idx < length; idx++) {
        *(dst_base + idx) = *(src_base + idx);
    }
}
