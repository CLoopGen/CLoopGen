#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  int dst_linesize;
extern  uint8_t *src;
extern  int src_linesize;
extern  int w;
extern  int h;
extern  int threshold;
extern int x;
extern int y;
extern int orig;
extern int filtered;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Linear Access with Pointer Arithmetic
    uint8_t *src_ptr = src;
    uint8_t *dst_ptr = dst;
    int total_elements = w * h;
    
    for (int i = 0; i < total_elements; ++i) {
        orig = src_ptr[i];
        filtered = dst_ptr[i];
        diff = orig - filtered;
        
        if (diff > 0) {
            if (diff <= -threshold)
                dst_ptr[i] = orig;
            else if (diff <= -2 * threshold)
                dst_ptr[i] = filtered - threshold;
        } else {
            if (diff >= threshold)
                dst_ptr[i] = orig;
            else if (diff >= 2 * threshold)
                dst_ptr[i] = filtered + threshold;
        }
    }
}
