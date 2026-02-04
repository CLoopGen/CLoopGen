#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el; i++) {
        for (int32 j = 0; j < 1; j++) {
            *(buf32 + i) = ((255 & (*(buf32 + i)) >> 24) | 
                           (65280 & (*(buf32 + i)) >> 8) | 
                           (16711680 & (*(buf32 + i)) << 8) | 
                           (4278190080U & (*(buf32 + i)) << 24));
        }
    }
}
