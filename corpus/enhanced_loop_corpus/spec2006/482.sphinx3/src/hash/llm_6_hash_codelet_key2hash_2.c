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
    char *temp_cp = key;
    uint32 temp_hash = hash;
    int32 temp_s = s;
    for (int i = 0; temp_cp[i] != '\0'; i++) {
        temp_hash += (temp_cp[i]) << temp_s;
        temp_s += 5;
        if (temp_s >= 25)
            temp_s -= 24;
    }
    hash = temp_hash;
    s = temp_s;
}
