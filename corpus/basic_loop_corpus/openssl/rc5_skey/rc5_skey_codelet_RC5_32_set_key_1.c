#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < j; i++) {
    if (++ii >= t)
        ii = 0;
    if (++jj >= c)
        jj = 0;
}

}
