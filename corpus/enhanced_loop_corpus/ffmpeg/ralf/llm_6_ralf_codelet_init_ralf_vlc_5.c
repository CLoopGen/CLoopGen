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
    uint16_t temp;
    for (i = 0; i < elems; i++) {
        temp = prefixes[lens[i]];
        codes[i] = temp;
        prefixes[lens[i]] = temp + 1;
    }
}
