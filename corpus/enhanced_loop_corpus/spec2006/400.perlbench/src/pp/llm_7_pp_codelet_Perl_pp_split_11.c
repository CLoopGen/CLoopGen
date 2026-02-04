#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_m = s;
    char val;
    for (int i = 0; local_m < strend; i++) {
        val = *local_m;
        if (val == '\n') break;
        local_m++;
    }
    m = local_m;
}
