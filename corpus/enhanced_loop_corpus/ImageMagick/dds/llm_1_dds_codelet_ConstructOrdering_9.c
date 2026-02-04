#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t count;
extern float dps[16];
extern float f;
extern ssize_t i;
extern ssize_t j;
extern unsigned char c;
extern unsigned char *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)count; i++) {
        for (j = i; j > 0; j--) {
            for (ssize_t k = 0; k < 1 && dps[j] < dps[j - 1]; k++) {
                f = dps[j];
                dps[j] = dps[j - 1];
                dps[j - 1] = f;
                c = o[j];
                o[j] = o[j - 1];
                o[j - 1] = c;
            }
        }
    }
}
