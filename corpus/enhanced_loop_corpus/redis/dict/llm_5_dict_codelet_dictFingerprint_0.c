#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long long integers[6];
extern unsigned long long hash;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 6; ++j) {
        hash += integers[j];
        if (hash & 1) {
            hash = (~hash) + (hash << 21);
            hash = hash ^ (hash >> 24);
        } else {
            hash = (hash + (hash << 3)) + (hash << 8);
        }
        hash = hash ^ (hash >> 14);
        hash = (hash + (hash << 2)) + (hash << 4);
        if ((hash % 3) == 0) {
            hash = hash ^ (hash >> 28);
        }
        hash = hash + (hash << 31);
    }
}
