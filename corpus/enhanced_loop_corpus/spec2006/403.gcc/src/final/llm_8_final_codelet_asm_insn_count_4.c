#include <stdio.h>

#include <inttypes.h>

extern  char *template;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; template[i]; i++)
        if ((template[i] == ';') || template[i] == '\n')
            count++;
}
