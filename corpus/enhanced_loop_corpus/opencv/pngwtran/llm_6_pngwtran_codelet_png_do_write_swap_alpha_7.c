#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , sp = dp = row; i < row_width; i++) {
    png_byte save[2];
    save[0] = sp[0];
    save[1] = sp[1];
    dp[0] = sp[2];
    dp[1] = sp[3];
    dp[2] = sp[4];
    dp[3] = sp[5];
    dp[4] = sp[6];
    dp[5] = sp[7];
    dp[6] = save[0];
    dp[7] = save[1];
    sp += 8;
    dp += 8;
}
}
