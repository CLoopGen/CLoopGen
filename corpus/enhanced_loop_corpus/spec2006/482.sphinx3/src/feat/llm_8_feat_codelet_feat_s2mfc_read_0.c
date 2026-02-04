#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **mfc;
extern int32 n_float32;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_float32; i += 2) {
        if (i + 1 < n_float32) {
            int32 val1 = *((int32 *)&(mfc[0][i]));
            int32 val2 = *((int32 *)&(mfc[0][i + 1]));
            
            int32 result1 = ((255 & (val1 >> 24)) | (65280 & (val1 >> 8)) | (16711680 & (val1 << 8)) | (4278190080U & (val1 << 24)));
            int32 result2 = ((255 & (val2 >> 24)) | (65280 & (val2 >> 8)) | (16711680 & (val2 << 8)) | (4278190080U & (val2 << 24)));

            *((int32 *)&(mfc[0][i])) = result1;
            *((int32 *)&(mfc[0][i + 1])) = result2;
        } else {
            int32 val = *((int32 *)&(mfc[0][i]));
            *((int32 *)&(mfc[0][i])) = ((255 & (val >> 24)) | (65280 & (val >> 8)) | (16711680 & (val << 8)) | (4278190080U & (val << 24)));
        }
    }
}
