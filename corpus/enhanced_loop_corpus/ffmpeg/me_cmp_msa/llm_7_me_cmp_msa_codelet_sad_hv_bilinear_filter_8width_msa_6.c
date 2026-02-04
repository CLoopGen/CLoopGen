#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_src = src;
    uint8_t *local_ref = ref;
    int32_t local_height = height;
    
    // Eliminate loop-carried dependency on global state updates
    // by deferring pointer updates until after loop
    for (ht_cnt = (local_height >> 2); ht_cnt--;) {
        // Introduce artificial WAR dependency: write before read via temporary
        uint32_t offset = 0;
        offset = (ht_cnt & 3) * 4; // Use loop index to create address variation
        
        uint8_t val_src = local_src[offset];
        uint8_t val_ref = local_ref[offset];
        
        // Create intra-loop RAW dependency chain
        val_src = (val_src ^ 0xFF) + val_ref;
        val_ref = (val_ref ^ val_src) + 1;
        
        local_src[offset] = val_src; // Write affects no future reads in this variant
        local_ref[offset] = val_ref;
        
        // Remove immediate stride update — defer to end
        {
        }
        ;
        {
        }
        ;
    }
    // Update globals only once after loop completes
    src += (4 * src_stride) * (local_height >> 2);
    ref += (4 * ref_stride) * (local_height >> 2);
}
