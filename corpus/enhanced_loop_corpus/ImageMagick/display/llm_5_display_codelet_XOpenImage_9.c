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
    for (i = 1; i < count; i++) {
        if (*files[i] == '-' || files[i] == NULL) {
            ; // Null statement to maintain loop structure
        } else {
            filelist[j++] = files[i];
        }
    }
}
