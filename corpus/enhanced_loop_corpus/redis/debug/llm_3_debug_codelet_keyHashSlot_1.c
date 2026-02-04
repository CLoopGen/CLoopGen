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
    // Variant 2: Consecutive reverse traversal from near end to start
    int start = s + 1;
    int temp_e = keylen - 1; // Start from the last valid index

    // Traverse backwards in consecutive manner
    for (; temp_e >= start; temp_e--) {
        if (key[temp_e] == '}') {
            break;
        }
    }

    // Assign the found index to global variable e
    e = temp_e;
}
