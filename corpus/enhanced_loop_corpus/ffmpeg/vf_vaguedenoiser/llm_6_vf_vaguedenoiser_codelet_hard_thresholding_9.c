#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float frac;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            temp = block[x];
            if ((temp >= 0 ? temp : -temp) <= threshold)
                block[x] = temp * frac;
        }
        block += stride;
    }
}
