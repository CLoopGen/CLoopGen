#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *key;
extern int keylen;
extern int s;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = s + 1;
    for (e = temp; e < keylen; e++) {
        temp = e; // Introduce WAW dependency: 'temp' is written each iteration, creating loop-carried dependence
        if (key[temp] == '}') { // RAW: use of 'temp' after write
            e = temp; // WAR: write to 'e' after read in condition index calculation
            break;
        }
    }
}
