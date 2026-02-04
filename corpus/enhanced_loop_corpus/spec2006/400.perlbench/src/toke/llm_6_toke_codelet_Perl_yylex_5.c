#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *PL_bufend;
extern char *t;
extern char win32_open;
extern char close;
extern I32 brackets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp_brackets = brackets;
    char local_close = close;
    char local_open = win32_open;
    char* local_t = t;
    char* local_bufend = PL_bufend;

    for (local_t++; local_t < local_bufend; local_t++) {
        if (*local_t == '\\' && local_t + 1 < local_bufend)
            local_t++;
        else if (*local_t == local_close && --temp_brackets <= 0)
            break;
        else if (*local_t == local_open)
            temp_brackets++;
    }
    brackets = temp_brackets;
    t = local_t;
}
