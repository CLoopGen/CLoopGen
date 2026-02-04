#include <stdio.h>

#include <inttypes.h>

extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = t + 1;
    for (; ((*temp) == ' ' || (*temp) == '\t' || (*temp) == '\n' || (*temp) == '\r' || (*temp) == '\f'); temp++)
        ;
    t = temp;
}
