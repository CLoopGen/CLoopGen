#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (c = 0; c < 16; c += 2) {
        OPJ_INT32 diff = tmp[(0) * 2 * 8 + c] - tmp[((1 + (0) * 2)) * 8 + c];
        tmp[(0) * 2 * 8 + c] = diff;
        if (c + 1 < 8) {
            OPJ_INT32 diff_next = tmp[(0) * 2 * 8 + c + 1] - tmp[((1 + (0) * 2)) * 8 + c + 1];
            tmp[(0) * 2 * 8 + c + 1] = diff_next;
        }
    }
}
