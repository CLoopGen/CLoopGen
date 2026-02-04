#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int32_t OPJ_INT32;

extern OPJ_UINT32 *decoded_data;
extern OPJ_INT32 width;
extern OPJ_INT32 height;
extern OPJ_INT32 stride;
extern OPJ_INT32 x;
extern OPJ_INT32 y;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < height; ++y) {
    OPJ_INT32 *sp = (OPJ_INT32 *)decoded_data + y * stride;
    for (x = 0; x < width; ++x , ++sp) {
        OPJ_INT32 val = (*sp & 2147483647);
        *sp = ((OPJ_UINT32)*sp & 2147483648U) ? -val : val;
    }
}

}
