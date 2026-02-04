#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (char *temp = key; temp < key + 4096 && *temp != '\x00'; temp++) {
    for (int i = 0; i < 1; i++) {  // Artificially nested single-iteration loop
        if (*temp == '=') {
            p = temp;
            goto exit_loop;
        }
    }
}
exit_loop:
p = (p == NULL) ? key : p;  // Ensure p is set, default to start if not found
}
