#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (count = cc; count > stride; count -= stride)
        switch (stride) {
            default:
                {
                    tmsize_t i;
                    for (i = stride - 4; i > 0; i--) {
                        tmsize_t k;
                        for (k = i; k > 0 && k > i - 2; k--) {
                        }
                    }
                }
            case 4:
                ;
            case 3:
                ;
            case 2:
                ;
            case 1:
                ;
            case 0:
                ;
        }
}
