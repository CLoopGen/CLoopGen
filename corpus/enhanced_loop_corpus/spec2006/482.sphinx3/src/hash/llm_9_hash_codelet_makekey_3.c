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
for (i = 0, j = 0; i < len; i += 2, j += 4) {
    if (i + 1 < len) {
        key[j] = 'A' + (data[i] & 15);
        key[j + 1] = 'J' + ((data[i] >> 4) & 15);
        key[j + 2] = 'A' + (data[i + 1] & 15);
        key[j + 3] = 'J' + ((data[i + 1] >> 4) & 15);
    } else {
        key[j] = 'A' + (data[i] & 15);
        key[j + 1] = 'J' + ((data[i] >> 4) & 15);
    }
}
}
