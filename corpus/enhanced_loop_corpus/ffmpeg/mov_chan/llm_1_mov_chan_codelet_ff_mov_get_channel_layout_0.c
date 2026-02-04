#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct MovChannelLayoutMap {
    uint32_t tag;
    uint64_t layout;
};


extern uint32_t tag;
extern int i;
extern  struct MovChannelLayoutMap *layout_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; layout_map[i].tag != 0 && layout_map[i].tag != tag; i++) {
    }
}
