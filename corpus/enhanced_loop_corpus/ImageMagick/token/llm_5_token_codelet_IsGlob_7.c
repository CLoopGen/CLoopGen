#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

extern  char *path;
extern MagickBooleanType status;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = path; *p != '\x00' && status != MagickTrue; p++) {
        switch (*p) {
          case '*':
          case '?':
          case '{':
          case '}':
          case '[':
          case ']':
            status = MagickTrue;
            goto end_loop;
          default:
            continue;
        }
    }
    end_loop: ;
}
