#include <stdio.h>

#include <inttypes.h>

extern size_t len;
extern size_t i;
extern unsigned char *p;
extern unsigned char c;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len; i += 4) {
    c = p[0] , p[0] = p[3] , p[3] = c;
    c = p[1] , p[1] = p[2] , p[2] = c;
}

}
