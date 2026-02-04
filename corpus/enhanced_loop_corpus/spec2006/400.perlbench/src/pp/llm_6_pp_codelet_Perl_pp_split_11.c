#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *strend;
extern char *m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = s;
    for (; temp < strend && *temp != '\n'; temp++)
        ;
    m = temp;
}
