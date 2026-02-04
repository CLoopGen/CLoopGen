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
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            udata[i]     = (3 * data[i]) ^ ((data[i] >> 30) + 1);
            udata[i + 1] = (3 * data[i + 1]) ^ ((data[i + 1] >> 30) + 1);
        } else {
            udata[i] = (3 * data[i]) ^ ((data[i] >> 30) + 1);
        }
    }
}
