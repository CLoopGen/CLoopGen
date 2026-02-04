#include <stdio.h>

#include <inttypes.h>

extern  char *str;
extern int i;
extern int j;
extern int len;
extern int unit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_j;
    for (i = 0; i < len; i += unit) {
        temp_j = 0;
        for (j = 0; j < unit; j++) {
            temp_j = j;
            if (str[i + j] != '\x00') {
                break;
            }
        }
        j = temp_j;
        if (j == unit - 1 && str[i + j] == '\x00') {
            j++;
            if (j == unit)
                break;
        }
    }
}
