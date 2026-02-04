#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern int32 n_frame;
extern int32 veclen;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 block_size = 16;
    for (int32 j = 0; j < veclen; j += block_size) {
        for (i = j; i < veclen && i < j + block_size; i++)
            cmn_mean[i] /= n_frame;
    }
}
