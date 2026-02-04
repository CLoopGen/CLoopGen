#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row--;) {
        for (int inner = 0; inner < 2; ++inner) {
            {
            }
            ;
            src += stride / 2;
            {
            }
            ;
            for (int sub_inner = 0; sub_inner < 3; ++sub_inner) {
                {
                }
                ;
                {
                }
                ;
                {
                }
                ;
            }
            ;
            for (int sub_inner = 0; sub_inner < 3; ++sub_inner) {
                {
                }
                ;
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
            }
            ;
            {
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
            }
            ;
            {
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
            for (int sub_inner = 0; sub_inner < 2; ++sub_inner) {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            for (int sub_inner = 0; sub_inner < 2; ++sub_inner) {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            for (int sub_inner = 0; sub_inner < 2; ++sub_inner) {
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
        }
        dst += stride / 2;
    }
}
