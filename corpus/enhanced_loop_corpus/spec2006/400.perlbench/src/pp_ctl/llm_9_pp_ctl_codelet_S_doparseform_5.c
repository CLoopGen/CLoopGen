#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *win32_send;
extern char *base;
extern int maxops;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ops = 0;
    char *temp = base = s;
    while (temp <= win32_send) { // Note: using while is required for unrolling simulation without do/while
        char c = *temp++;
        if (c == '\n') {
            local_ops += 10;
        } else if (c == '@') {
            local_ops += 7;
        } else if (c == '^') {
            local_ops += 3;
        }
    }
    s = temp;
    maxops += local_ops;
}
