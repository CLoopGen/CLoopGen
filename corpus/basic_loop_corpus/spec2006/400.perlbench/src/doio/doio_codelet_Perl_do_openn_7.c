#include <stdio.h>

#include <inttypes.h>

extern char *name;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; ((*name) == ' ' || (*name) == '\t' || (*name) == '\n' || (*name) == '\r' || (*name) == '\f'); name++)
    ;

}
