#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[4];
    for (i = 0; i < len; i += 4) {
        indices[0] = i;
        indices[1] = i + 1;
        indices[2] = i + 2;
        indices[3] = i + 3;
        c = p[indices[0]], p[indices[0]] = p[indices[3]], p[indices[3]] = c;
        c = p[indices[1]], p[indices[1]] = p[indices[2]], p[indices[2]] = c;
    }
}
