#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (st = (char *)suitestr; *st != '\x00'; st++) {
        delim_count += (*st == ',');
    }
}
