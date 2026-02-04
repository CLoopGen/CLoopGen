#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tile;
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = i;
    char *temp_p = p;
    for (i = tile; (temp_i != 0) && (*temp_p != '\x00');) {
        if (*temp_p == '\xff') {
            temp_i--;
        }
        temp_p++;
    }
    i = temp_i;
    p = temp_p;
}
