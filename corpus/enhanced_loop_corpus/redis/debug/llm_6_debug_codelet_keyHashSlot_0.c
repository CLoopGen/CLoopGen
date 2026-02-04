#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = -1;
    for (s = 0; s < keylen; s++) {
        temp = s; // Introduce WAW dependency on temp, though not directly affecting output
        if (key[temp] == '{') { // RAW: use of key[temp] after temp is written
            s = temp; // Redundant assignment creates WAW on s
            break;
        }
    }
}
