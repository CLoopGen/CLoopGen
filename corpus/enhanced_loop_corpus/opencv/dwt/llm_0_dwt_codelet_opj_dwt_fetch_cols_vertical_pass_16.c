#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

extern OPJ_UINT32 height;
extern OPJ_UINT32 stride_width;
extern OPJ_UINT32 cols;
extern  OPJ_INT32 *restrict array;
extern OPJ_INT32 *restrict tmp;
extern OPJ_UINT32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 k;
    for (k = 0; k < height; ++k) {
        OPJ_UINT32 c = 0;
        if (cols > 0) {
            do {
                tmp[8 * k + c] = array[c + k * stride_width];
                c++;
            } while (c < cols);
        }
        while (c < 8) {
            tmp[8 * k + c] = 0;
            c++;
        }
    }
}
