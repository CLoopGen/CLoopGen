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
        i = 0;
        for (; i < n; ) {
            udata[i] = (2 * data[i]) ^ (data[i] >> 31);
            i++;
        }
    }
}
