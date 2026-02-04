#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern  char *key;
extern  char *cp;
extern int32 s;
extern uint32 hash;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_cp = key;
    uint32 local_hash = hash;
    int32 local_s = s;
    for (; *local_cp; local_cp++) {
        int32 shifted = (*local_cp) << local_s;
        local_hash += shifted;
        local_s = (local_s + 5) % 24;
    }
    hash = local_hash;
    s = local_s;
}
