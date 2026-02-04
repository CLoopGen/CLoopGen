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
    int local_j = j;
    for (i = 1; i < count; i++) {
        if (files[i] && *files[i] != '-') {
            filelist[local_j++] = files[i];
        }
    }
    j = local_j;
}
