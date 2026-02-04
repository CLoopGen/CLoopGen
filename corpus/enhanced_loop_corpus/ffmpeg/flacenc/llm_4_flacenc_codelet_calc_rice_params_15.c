#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t udata[65535];
extern  int32_t *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        int32_t val = data[i];
        if (val >= 0) {
            udata[i] = (2 * val) ^ 0;
        } else {
            udata[i] = (2 * val) ^ 1;
        }
    }
}
