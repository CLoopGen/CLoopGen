#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < 7; k++) {
    *wr++ = *wp++ / max;
}

}
