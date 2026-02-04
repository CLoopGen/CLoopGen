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
    if (n > 0) {
        udata[0] = (2 * data[0]) ^ (data[0] >> 31);
        for (i = 1; i < n; i++) {
            udata[i] = (2 * data[i]) ^ (data[i] >> 31) ^ udata[i-1];
        }
    }
}
