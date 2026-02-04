#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile;
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_counter = (i == tile) ? tile : i;
    char prev = '\x00';
    for (i = tile; (local_counter != 0) && (*p != '\x00');) {
        if (*p == '\xff' || prev == '\xff') {
            local_counter--;
        }
        prev = *p;
        p++;
        local_counter = (local_counter < 0) ? 0 : local_counter;
    }
    i = local_counter;
}
