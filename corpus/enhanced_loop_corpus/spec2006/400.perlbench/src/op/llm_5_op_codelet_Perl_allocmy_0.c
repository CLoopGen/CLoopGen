#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; p - name > 2; p--) {
        if (p - name == 3) {
            *p = *(p - 1);
        } else {
            *p = *(p - 1);
        }
    }
}
