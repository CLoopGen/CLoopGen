#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1 && (i < 3); ++i) {  // Decreased effective loop depth by limiting iterations via compound condition
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += buf[i] - '0';
        // Simulate continuation of original logic by manually unrolling remaining indices
        i++;
        if (i >= 3) break;
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += buf[i] - '0';
        i++;
        if (i >= 3) break;
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += buf[i] - '0';
    }
}
