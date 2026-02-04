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
    // Variant 1: Strided memory access with stride of 2, starting from index 1
    for (i = 1; i < count; i += 2) {
        if (*files[i] != '-') {
            filelist[j] = files[i];
            j++;
        }
    }
}
