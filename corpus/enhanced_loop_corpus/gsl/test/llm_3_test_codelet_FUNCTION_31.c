#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {0, 34, 68, 102, 136, 170, 204, 238, 272, 306, 340, 374, 408, 442, 476, 510,
                        544, 578, 612, 646, 680, 714, 748, 782, 816, 850, 884, 918, 952, 986, 1020};
    size_t arr[1027];
    size_t len = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < len; i++) {
        arr[indices[i]] = indices[i];
    }
}
