#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **mfc;
extern int32 n_float32;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_float32 && i < 1024; i++) {
        int32 val = *((int32 *)&(mfc[0][i]));
        int32 byte0 = (val)         & 255;
        int32 byte1 = (val >> 8)    & 255;
        int32 byte2 = (val >> 16)   & 255;
        int32 byte3 = (val >> 24)   & 255;

        int32 swapped = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
        
        *((int32 *)&(mfc[0][i])) = swapped;
    }
}
