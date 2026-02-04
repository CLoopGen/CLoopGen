#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int64_t *error;
extern int error_count;
extern uint8_t *side_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (error_count > 0) {
        for (i = 0; i < error_count; i += 2) {
            ((((union unaligned_64 *)(side_data + 8 + 8 * i))->l) = (error[i]));
            if ((i + 1) < error_count)
                ((((union unaligned_64 *)(side_data + 8 + 8 * (i + 1)))->l) = (error[i + 1]));
        }
    }
}
