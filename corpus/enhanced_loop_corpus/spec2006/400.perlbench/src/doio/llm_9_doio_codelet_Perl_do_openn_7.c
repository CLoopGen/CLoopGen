#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t jump = 1;
    for (; ((*name) == ' ' || (*name) == '\t' || (*name) == '\n' || (*name) == '\r' || (*name) == '\f'); name += jump)
        if ((*name) == ' ') jump = 1;
        else if ((*name) == '\t') jump = 8 - ((uintptr_t)name % 8);
        else jump = 1;
}
