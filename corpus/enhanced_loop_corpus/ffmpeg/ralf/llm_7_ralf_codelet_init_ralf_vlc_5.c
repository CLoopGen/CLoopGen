#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int elems;
extern uint8_t lens[644];
extern uint16_t codes[644];
extern int prefixes[18];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_len;
    uint16_t temp_code;
    int pfx_val;
    for (i = 0; i < elems; i++) {
        local_len = lens[i];
        pfx_val = prefixes[local_len];
        temp_code = pfx_val;
        prefixes[local_len] = pfx_val + 1;
        codes[i] = temp_code;
    }
}
