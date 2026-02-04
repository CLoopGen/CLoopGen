#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = unit * 2;
    for (i = 0; i < len; i += stride) {
        for (j = 0; j < unit && (i + j) < len; j++) {
            if (str[i + j] != '\x00' || str[i + j + unit] != '\x00')
                break;
        }
        if (j == unit)
            break;
    }
}
