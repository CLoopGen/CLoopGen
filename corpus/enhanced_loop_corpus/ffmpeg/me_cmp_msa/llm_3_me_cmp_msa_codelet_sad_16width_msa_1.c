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
const int32_t src_offset = 4 * src_stride;
const int32_t ref_offset = 4 * ref_stride;
uint8_t *src_ptr = src;
uint8_t *ref_ptr = ref;

for (ht_cnt = (height >> 2); ht_cnt--;) {
    {
        // Simulate indirect-like access via offset calculation
        src_ptr += src_offset;
        ref_ptr += ref_offset;
    }
    ;
}

src = src_ptr;
ref = ref_ptr;
}
