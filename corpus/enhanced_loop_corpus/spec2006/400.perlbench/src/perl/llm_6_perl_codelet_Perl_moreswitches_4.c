#include <stdio.h>

#include <inttypes.h>

extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_s = s + 1;
    for (; ((((*temp_s) >= 'A' && (*temp_s) <= 'Z') || ((*temp_s) >= 'a' && (*temp_s) <= 'z')) || ((*temp_s) >= '0' && (*temp_s) <= '9') || (*temp_s) == '_'); temp_s++)
        ;
    s = temp_s;
}
