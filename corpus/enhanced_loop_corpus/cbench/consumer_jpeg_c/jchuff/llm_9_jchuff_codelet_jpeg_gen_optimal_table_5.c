#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 514; i++) {
        int idx = i >> 1;
        others[idx] = (i & 1) ? -2 : -1;
    }
}
