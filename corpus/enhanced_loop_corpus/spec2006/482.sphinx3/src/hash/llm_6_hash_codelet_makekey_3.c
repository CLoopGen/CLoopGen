#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uint8;

typedef int int32;

extern uint8 *data;
extern int32 len;
extern char *key;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_j;
    for (i = 0, j = 0; i < len; i++) {
        temp_j = j;
        key[temp_j] = 'A' + (data[i] & 15);
        key[temp_j + 1] = 'J' + ((data[i] >> 4) & 15);
        j += 2;
    }
}
