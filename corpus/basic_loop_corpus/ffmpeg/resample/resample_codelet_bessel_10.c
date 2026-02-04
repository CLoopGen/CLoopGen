#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double v;
extern double lastv;
extern double t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; v != lastv; i++) {
    lastv = v;
    t *= x / (i * i);
    v += t;
}

}
