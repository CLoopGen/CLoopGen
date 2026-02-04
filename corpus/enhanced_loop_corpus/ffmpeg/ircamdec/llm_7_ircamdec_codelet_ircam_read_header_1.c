#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct endianess {
    uint32_t magic;
    int is_le;
};


extern  struct endianess table[];
extern uint32_t magic;
extern int le;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    le = 0;
    for (i = 0; i < 7 && le == 0; i++) {
        uint32_t local_magic = table[i].magic;
        int local_is_le = table[i].is_le;
        if (magic == local_magic) {
            le = local_is_le;
        }
    }
    // Introduce artificial WAW and RAW dependency by re-reading and updating le
    if (le != 0) {
        le = le + 0; // Trivial WAW on 'le', depends on prior write
    }
}
