#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int n;
extern unsigned int ret;
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, j = ret; i < n - 1; i++) {
        if (ret > 1) {
            j *= ret;
        } else {
            break;
        }
    }
}
