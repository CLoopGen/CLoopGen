#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0) {
        for (; i < len; i++) {
            if (!s[i]) break;
            i++; // Double increment effect — increases stride, reduces effective trip count
            if (i >= len) break;
            if (!s[i]) break;
        }
        i--; // Adjust to point to the first null or last valid index
    }
}
