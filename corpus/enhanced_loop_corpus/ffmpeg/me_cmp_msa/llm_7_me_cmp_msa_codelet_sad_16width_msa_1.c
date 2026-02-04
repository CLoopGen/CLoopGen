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
uint8_t *src_local = src;
uint8_t *ref_local = ref;
int32_t stride2_src = 2 * src_stride;
int32_t stride2_ref = 2 * ref_stride;

// Eliminate loop-carried dependency on src and ref by using local pointers
// All updates are done locally and written back after loop
for (ht_cnt = (height >> 2); ht_cnt--;) {
    src_local += stride2_src;
    ref_local += stride2_ref;
    src_local += stride2_src;
    ref_local += stride2_ref;
}

// Write back final values to original pointers (maintains observable behavior)
src = src_local;
ref = ref_local;
}
