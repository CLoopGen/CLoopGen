#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = len - (len % unit);
    for (i = 0; i < limit; i += unit) {
        int match = 1;
        for (j = 0; j < unit; j++) {
            match &= (str[i + j] == '\x00');
        }
        if (match)
            break;
    }
}
