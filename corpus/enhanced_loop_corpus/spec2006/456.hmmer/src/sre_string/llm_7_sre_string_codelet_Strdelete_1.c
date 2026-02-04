#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *base = s1 + pos;
    int len = 0;
    for (char *p = base; *p; p++)
        len++;
    for (int i = 0; i < len - 1; i++)
        base[i] = base[i + 1];
    if (len > 0)
        base[len - 1] = 0;
}
