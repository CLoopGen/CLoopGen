#include <stdio.h>

#include <inttypes.h>

extern  char *port;
extern  char *port_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with lookahead unrolling (process two characters per iteration)
    char *p = port;
    while (1) {
        if (p >= port_end) break;
        if (*p < '0' || *p > '9') break;
        p++;
        // Look ahead one more character without duplicating logic
        if (p >= port_end || *p < '0' || *p > '9') {
            port_end = p;
            break;
        }
        p++;
    }
    port_end = p;
}
