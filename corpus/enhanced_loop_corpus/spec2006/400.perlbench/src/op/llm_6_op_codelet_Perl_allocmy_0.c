#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = p;
    for (; temp - name > 2; temp--) {
        *(temp + 1) = *temp;
    }
    *name = *(name + 1);
}
