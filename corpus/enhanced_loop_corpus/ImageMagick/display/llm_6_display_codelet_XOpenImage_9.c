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
    char* temp_ptr;
    for (i = 1; i < count; i++) {
        temp_ptr = files[i];
        if (*temp_ptr != '-') {
            filelist[j] = temp_ptr;
            j++;
        }
    }
}
