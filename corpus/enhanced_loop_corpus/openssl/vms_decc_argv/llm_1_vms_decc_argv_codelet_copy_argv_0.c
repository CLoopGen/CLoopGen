#include <stdio.h>

#include <inttypes.h>

extern char **newargv;
extern char *argv[];
extern int i;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (count > 0) {
        for (i = 0; i < count; i += 2) {
            newargv[i] = argv[i];
            if (i + 1 < count)
                newargv[i + 1] = argv[i + 1];
        }
    }
}
