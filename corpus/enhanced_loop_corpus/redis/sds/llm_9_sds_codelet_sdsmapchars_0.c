#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *sds;

extern sds s;
extern  char *from;
extern  char *to;
extern size_t setlen;
extern size_t j;
extern size_t i;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 4;
    for (j = 0; j < l; j++) {
        int found = 0;
        for (i = 0; i < setlen && !found; i++) {
            if (s[j] == from[i]) {
                s[j] = to[i];
                found = 1;
            }
        }
        if ((j % stride) == 0) {
            for (size_t k = 0; k < stride && j + k < l; k++) {
                for (i = 0; i < setlen; i++) {
                    if (s[j + k] == from[i]) {
                        s[j + k] = to[i];
                        break;
                    }
                }
            }
            j += stride - 1;
        }
    }
}
