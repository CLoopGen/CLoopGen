#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double sum;
extern double t;
extern double y;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; t > 9.9999999999999998E-13; i++) {
    sum += t;
    t *= y / ((double)i * i);
}

}
