#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern  char *key;
extern  char *cp;
extern char c;
extern int32 s;
extern uint32 hash;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_cp = key;
    uint32 temp_hash = 0;
    int32 temp_s = s;
    char temp_c;

    for (int i = 0; temp_cp[i]; i++) {
        temp_c = temp_cp[i];
        temp_c = ((((temp_c) >= 'a') && ((temp_c) <= 'z')) ? (temp_c - 32) : temp_c);
        temp_hash += temp_c << temp_s;
        temp_s += 5;
        if (temp_s >= 25)
            temp_s -= 24;
    }
    hash = temp_hash;
}
