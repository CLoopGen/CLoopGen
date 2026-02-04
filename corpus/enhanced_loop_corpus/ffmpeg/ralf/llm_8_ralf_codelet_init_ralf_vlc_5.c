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
    int j;
    for (i = 0; i < elems && i < 644; i += 2) {
        codes[i] = prefixes[lens[i]]++;
        if (i + 1 < elems) {
            codes[i + 1] = prefixes[lens[i + 1]]++;
        }
    }
}
