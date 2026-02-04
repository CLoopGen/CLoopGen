#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height; loop_cnt--;) {
        for (int outer = 2; outer > 0; outer--) {
            for (int inner = 1; inner > 0; inner--) {
                {
                    {
                        {
                        }
                        {
                        }
                    }
                    {
                    }
                }
                ;
                if (outer == 2 && inner == 1) {
                    src += src_stride;
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
                {
                }
                ;
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                {
                    {
                    }
                    ;
                    {
                    }
                    ;
                }
                ;
                {
                }
                ;
                {
                }
                ;
                {
                }
                ;
                {
                }
                ;
                if (outer == 2 && inner == 1) {
                    dst += dst_stride;
                }
            }
        }
    }
}
