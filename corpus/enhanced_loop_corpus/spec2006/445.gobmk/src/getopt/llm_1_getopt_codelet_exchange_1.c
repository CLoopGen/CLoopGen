#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        tem = argv[bottom + i];
        argv[bottom + i] = argv[middle + i];
        argv[middle + i] = tem;
        if (i + 1 < len) {
            tem = argv[bottom + i + 1];
            argv[bottom + i + 1] = argv[middle + i + 1];
            argv[middle + i + 1] = tem;
        }
    }
}
}
