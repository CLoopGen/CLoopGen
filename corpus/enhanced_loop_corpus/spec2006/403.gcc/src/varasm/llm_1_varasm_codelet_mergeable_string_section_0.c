#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len && j < unit; i += unit) { // Reduced inner loop into condition of outer loop
    j = 0;
    for (; j < unit && str[i + j] != '\x00'; j++);
    if (j == unit)
        break;
}
}
