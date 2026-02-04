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
        temp = s; // Introduce WAW dependency: temp is overwritten each iteration
        if (key[temp] == '{') { // RAW dependency: use of temp after write
            s = temp; // WAR hazard avoided by ensuring order via loop control
            break;
        }
    }
}
