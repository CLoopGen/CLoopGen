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
for (i = 0 , j = 0; i < len; i++ , j += 2) {
    if ((data[i] & 15) == 0) {
        key[j] = 'A';
    } else {
        key[j] = 'A' + (data[i] & 15);
    }
    if (((data[i] >> 4) & 15) == 0) {
        key[j + 1] = 'J';
        continue;
    }
    key[j + 1] = 'J' + ((data[i] >> 4) & 15);
}
}
