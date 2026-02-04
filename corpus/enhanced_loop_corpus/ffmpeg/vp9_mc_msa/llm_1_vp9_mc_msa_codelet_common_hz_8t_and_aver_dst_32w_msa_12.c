#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    src += src_stride;
    for (int outer = 0; outer < 2; ++outer) {
        for (int inner = 0; inner < 7; ++inner) {
            switch (outer * 7 + inner) {
                case 0: { } break;
                case 1: { } break;
                case 2: { } break;
                case 3: { } break;
                case 4: { } break;
                case 5: { } break;
                case 6: { } break;
                case 7: { } break;
                case 8: { } break;
                case 9: { } break;
                case 10: { } break;
                case 11: { } break;
                case 12: { } break;
                default: { } break;
            }
        }
    }
    {
    }
    ;
    {
    }
    ;
    {
    }
    ;
    dst += dst_stride;
}
}
