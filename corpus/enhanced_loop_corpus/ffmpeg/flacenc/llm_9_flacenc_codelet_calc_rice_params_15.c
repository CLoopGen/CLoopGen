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
        udata[i] = (5 * data[i] + data[i] * data[i]) ^ ((data[i] >> 31) & 1);
        udata[i] ^= (data[i] < 0) ? 0xFFFFFFFF : 0x00000000;
    }
}
