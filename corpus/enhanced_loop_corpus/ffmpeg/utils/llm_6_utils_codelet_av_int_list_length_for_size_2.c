#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int i;
extern uint32_t t;
extern uint32_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = 0;
    for (i = 0; l[i] != t; i++) {
        temp = l[i];
    }
    // Introduce a WAW dependency on 'temp' (though not loop-carried), and make 'l[i]' read before write in next iteration via temp.
    // RAW dependency: 'l[i]' must be loaded before assignment to 'temp'
    // Loop-carried dependency: none in terms of 'i', but data flow through 'temp' is sequential.
}
