#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int chroma_stride;
extern uint8_t *dest_u;
extern uint8_t *dest_v;
extern uint16_t val_no_chroma;
extern size_t mb_max_x;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 && mb_max_x > 0; ++i)
    for (j = 0; j < mb_max_x; ++j)
        *(uint16_t *)(dest_u + (i * chroma_stride) + (j << 1)) = val_no_chroma,
        *(uint16_t *)(dest_v + (i * chroma_stride) + (j << 1)) = val_no_chroma;
}
