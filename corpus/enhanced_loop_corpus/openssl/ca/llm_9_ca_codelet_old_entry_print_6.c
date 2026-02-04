#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_pbuf = pbuf;
    int count = 22 - j;
    for (int i = 0; i < count; i++) {
        local_pbuf[i] = ' ';
    }
    pbuf = local_pbuf + count;
    j = count;
}
