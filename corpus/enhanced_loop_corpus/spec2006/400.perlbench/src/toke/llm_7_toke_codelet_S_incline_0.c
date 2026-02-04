#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    t = s;
    char prev_t_val[2] = {0};
    for (int i = 0; !((prev_t_val[i % 2] = *t), (*t) == ' ' || (*t) == '\t' || (*t) == '\n' || (*t) == '\r' || (*t) == '\f'); t++, i++) {
        prev_t_val[(i + 1) % 2] = prev_t_val[i % 2];
    }
}
