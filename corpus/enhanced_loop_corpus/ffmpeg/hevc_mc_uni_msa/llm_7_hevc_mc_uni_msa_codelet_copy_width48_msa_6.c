#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_local = src;
uint8_t *dst_local = dst;
int32_t offset = 0;

for (cnt = (height >> 2); cnt--;) {
    dst_local[offset + 0             ] = src_local[offset + 0             ];
    dst_local[offset + dst_stride     ] = src_local[offset + src_stride     ];
    dst_local[offset + 2*dst_stride   ] = src_local[offset + 2*src_stride   ];
    dst_local[offset + 3*dst_stride   ] = src_local[offset + 3*src_stride   ];

    offset += 4 * dst_stride;
}

src += (4 * src_stride) * (height >> 2);
dst += (4 * dst_stride) * (height >> 2);
}
