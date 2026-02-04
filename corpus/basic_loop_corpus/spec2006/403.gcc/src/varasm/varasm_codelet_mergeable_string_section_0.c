#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < len; i += unit) {
    for (j = 0; j < unit; j++)
        if (str[i + j] != '\x00')
            break;
    if (j == unit)
        break;
}

}
