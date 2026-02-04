#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern  int32_t *src;
extern int len;
extern int i;
extern unsigned int mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 8) {
    int j = 0;
    if (i + j < len) {
        dst[i + j] = src[i + j] * mul;
        j++;
        if (i + j < len) {
            dst[i + j] = src[i + j] * mul;
            j++;
            if (i + j < len) {
                dst[i + j] = src[i + j] * mul;
                j++;
                if (i + j < len) {
                    dst[i + j] = src[i + j] * mul;
                    j++;
                    if (i + j < len) {
                        dst[i + j] = src[i + j] * mul;
                        j++;
                        if (i + j < len) {
                            dst[i + j] = src[i + j] * mul;
                            j++;
                            if (i + j < len) {
                                dst[i + j] = src[i + j] * mul;
                                j++;
                                if (i + j < len) {
                                    dst[i + j] = src[i + j] * mul;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
}
