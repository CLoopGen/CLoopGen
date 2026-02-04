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
        temp = e; // Introduce WAW dependency: temp is written before being used in next iteration
        if (key[temp] == '}') { // RAW: use of key[temp] after load, dependent on e via indexing
            e = temp; // WAR: write to e after read in loop condition (conceptually, though e is updated only once)
            break;
        }
    }
}
