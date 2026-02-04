#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_y;
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced loop depth by eliminating any potential nesting (already flat, so ensure maximal simplicity)
    // This variant keeps the original loop but ensures no nested blocks or extra scopes exist
    // Although it appears identical, it reflects minimalistic loop structure with no internal loops
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++)
        dst[y * stride_dst] = src[y * stride_src];
}
