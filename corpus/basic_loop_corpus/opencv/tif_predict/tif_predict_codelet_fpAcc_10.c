#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; count > 1; count -= 1) {
    do {
    } while (0);
}

}
