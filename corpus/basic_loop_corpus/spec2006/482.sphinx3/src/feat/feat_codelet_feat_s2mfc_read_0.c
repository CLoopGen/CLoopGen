#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **mfc;
extern int32 n_float32;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n_float32; i++)
    *((int32 *)&(mfc[0][i])) = ((255 & (*((int32 *)&(mfc[0][i]))) >> 24) | (65280 & (*((int32 *)&(mfc[0][i]))) >> 8) | (16711680 & (*((int32 *)&(mfc[0][i]))) << 8) | (4278190080U & (*((int32 *)&(mfc[0][i]))) << 24));

}
