#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char **filelist;
extern char **files;
extern int count;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i += 2) {
        if (i + 1 < count && *files[i + 1] != '-') {
            filelist[j++] = files[i + 1];
        }
    }
}
