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
    // Variant 1: Strided memory access (stride of 2)
    for (p = path; *p != '\x00'; p += 2) {
        switch (*p) {
          case '*':
          case '?':
          case '{':
          case '}':
          case '[':
          case ']':
            {
                status = MagickTrue;
                break;
            }
          default:
            break;
        }
        // Ensure we don't overrun if next char is null
        if (*(p + 1) == '\x00') break;
    }
}
