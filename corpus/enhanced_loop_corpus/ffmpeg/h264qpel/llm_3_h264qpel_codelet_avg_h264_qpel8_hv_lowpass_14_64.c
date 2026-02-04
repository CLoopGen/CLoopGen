#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t *t = tmp;
    uint16_t *s = src;
    for (i = 0; i < h + 5; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = j + 1;
            t[j] = (s[idx] + s[idx+1]) * 20 
                 - (s[idx-1] + s[idx+2]) * 5 
                 + (s[idx-2] + s[idx+3]) + pad;
        }
        t += tmpStride;
        s += srcStride;
    }
}
