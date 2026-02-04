#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *ptr = (char *)suitestr;
    int count = 0;
    int step;
    for (step = 0; ptr[step] != '\x00' && ptr[step + 1] != '\x00'; step += 2) {
        if (ptr[step] == ',')
            count++;
        if (ptr[step + 1] == ',')
            count++;
    }
    for (; ptr[step] != '\x00'; step++) {
        if (ptr[step] == ',')
            count++;
    }
    delim_count = count;
}
