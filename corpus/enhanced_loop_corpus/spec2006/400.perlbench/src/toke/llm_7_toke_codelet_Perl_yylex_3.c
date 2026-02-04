#include <stdio.h>

#include <inttypes.h>

extern char *PL_bufend;
extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char local_s = *s;
    char* temp_t = t + 1;
    for (; temp_t < PL_bufend && *temp_t != local_s; ) {
        if (*temp_t == '\\' && (*(temp_t + 1) == '\\' || *(temp_t + 1) == local_s)) {
            temp_t++;
        }
        temp_t++;
    }
    t = temp_t;
}
