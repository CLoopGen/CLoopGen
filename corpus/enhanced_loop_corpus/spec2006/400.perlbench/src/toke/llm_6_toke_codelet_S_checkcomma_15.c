#include <stdio.h>

#include <inttypes.h>

extern char *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_w = w;
    for (; *local_w && (local_w[0] == ' ' || local_w[0] == '\t' || local_w[0] == '\n' || local_w[0] == '\r' || local_w[0] == '\f'); )
        local_w++;
    w = local_w;
}
