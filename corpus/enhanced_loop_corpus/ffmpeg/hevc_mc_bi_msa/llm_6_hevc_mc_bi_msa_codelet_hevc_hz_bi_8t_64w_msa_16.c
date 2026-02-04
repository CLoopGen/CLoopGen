#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    uint8_t temp_load_0 = src0_ptr[0];
    uint8_t temp_load_1 = src0_ptr[1];
    uint8_t temp_load_2 = src0_ptr[2];
    uint8_t temp_load_3 = src0_ptr[3];
    int16_t temp_load_4 = src1_ptr[0];
    int16_t temp_load_5 = src1_ptr[1];
    int16_t temp_load_6 = src1_ptr[2];
    int16_t temp_load_7 = src1_ptr[3];

    int16_t sum_0 = temp_load_4 + temp_load_5;
    int16_t sum_1 = temp_load_6 + temp_load_7;
    int16_t combined_sum = sum_0 + sum_1;

    dst[0] = (uint8_t)(temp_load_0 + (combined_sum & 0xFF));
    dst[1] = (uint8_t)(temp_load_1 + ((combined_sum >> 2) & 0xFF));
    dst[2] = (uint8_t)(temp_load_2 + ((combined_sum >> 4) & 0xFF));
    dst[3] = (uint8_t)(temp_load_3 + ((combined_sum >> 6) & 0xFF));

    src1_ptr += src2_stride;
    src0_ptr += src_stride;
    dst += dst_stride;
}
}
