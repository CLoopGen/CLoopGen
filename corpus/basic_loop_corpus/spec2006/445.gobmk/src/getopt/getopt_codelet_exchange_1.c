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
for (i = 0; i < len; i++) {
    tem = argv[bottom + i];
    argv[bottom + i] = argv[middle + i];
    argv[middle + i] = tem;
    ;
}

}
