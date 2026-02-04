#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; ++i) {
        for (int j = 0; j < 1; ++j) {  // Increased nesting depth: added inner loop with fixed iteration
            if (buf[i] < '0' || buf[i] > '9') {
                err = 0;
                goto exit_nested;
            }
            err *= 10;
            err += buf[i] - '0';
        }
    }
exit_nested:;
}
