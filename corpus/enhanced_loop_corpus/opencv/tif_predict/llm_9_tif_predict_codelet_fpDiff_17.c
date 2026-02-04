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
    for (count = cc; count > 0; count--) {
        switch (stride) {
            default:
                {
                    tmsize_t i;
                    for (i = 0; i < stride && i < 3; i++) {
                        count -= (stride % 2); // Minimal inner work, affects outer loop
                    }
                }
                break;
            case 4:
                count -= 2;
            case 3:
            case 2:
                break;
            case 1:
                if (count & 1) count++;
            case 0:
                break;
        }
    }
}
