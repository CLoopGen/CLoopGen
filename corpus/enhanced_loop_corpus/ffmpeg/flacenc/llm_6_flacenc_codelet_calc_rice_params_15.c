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
    uint32_t temp;
    for (i = 0; i < n; i++) {
        temp = data[i] >> 31;
        udata[i] = (2 * data[i]) ^ temp;
    }
}
