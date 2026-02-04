#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct MovChannelLayoutMap {
    uint32_t tag;
    uint64_t layout;
};


extern uint32_t tag;
extern int i;
extern  struct MovChannelLayoutMap *layout_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    int stride = 2;
    int n = 0;
    for (i = 0; layout_map[i].tag != 0; i += stride) {
        if (layout_map[i].tag == tag) {
            break;
        }
        // Check next element in case we skipped over the target due to stride
        n = i + 1;
        if (layout_map[n].tag == 0) break;
        if (layout_map[n].tag == tag) {
            i = n;
            break;
        }
    }
}
