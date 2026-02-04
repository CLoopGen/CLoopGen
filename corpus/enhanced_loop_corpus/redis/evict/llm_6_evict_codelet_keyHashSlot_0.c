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
        temp = s; // Introduce WAW dependency on temp, though not directly used later
        if (key[s] == '{' && temp == s) { // Add data dependency on temp to condition
            s = temp; // Create RAW: use temp after write, and WAW on s
            break;
        }
    }
}
