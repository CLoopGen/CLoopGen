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
        for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth with a single-iteration inner loop
            if (*files[i] != '-') {
                filelist[j++] = files[i];
            }
        }
    }
}
