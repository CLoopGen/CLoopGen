#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **mfc;
extern int32 n_float32;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp;
    for (i = 0; i < n_float32; i++) {
        temp = *((int32 *)&(mfc[0][i]));
        temp = ((255 & (temp >> 24)) | (65280 & (temp >> 8)) | (16711680 & (temp << 8)) | (4278190080U & (temp << 24)));
        *((int32 *)&(mfc[0][i])) = temp;
    }
}
