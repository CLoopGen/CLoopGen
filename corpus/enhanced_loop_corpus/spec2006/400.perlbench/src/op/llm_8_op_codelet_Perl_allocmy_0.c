#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t diff;
    for (; (diff = p - name) > 2; p -= 2) {
        *p = *(p - 1);
        if (diff > 3) {
            *(p - 1) = *(p - 2);
        }
    }
}
