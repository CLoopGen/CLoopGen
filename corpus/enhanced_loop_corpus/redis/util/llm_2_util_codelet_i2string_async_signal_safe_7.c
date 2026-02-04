#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse, with stride -2)
    // The buffer is traversed from a higher offset down to 0 with a fixed stride.
    // We assume buf is at least 32 bytes ahead to allow stepping back by 2 each time for 16 iterations.
    char *temp_buf = buf - 30;  // Start from an adjusted position to allow strided access
    for (ix = 0; ix < 16; ++ix, temp_buf -= 2) {
        switch (*temp_buf) {
          case '0':
            *temp_buf = 'f';
            break;
          case '1':
            *temp_buf = 'e';
            break;
          case '2':
            *temp_buf = 'd';
            break;
          case '3':
            *temp_buf = 'c';
            break;
          case '4':
            *temp_buf = 'b';
            break;
          case '5':
            *temp_buf = 'a';
            break;
          case '6':
            *temp_buf = '9';
            break;
          case '7':
            *temp_buf = '8';
            break;
          case '8':
            *temp_buf = '7';
            break;
          case '9':
            *temp_buf = '6';
            break;
          case 'a':
            *temp_buf = '5';
            break;
          case 'b':
            *temp_buf = '4';
            break;
          case 'c':
            *temp_buf = '3';
            break;
          case 'd':
            *temp_buf = '2';
            break;
          case 'e':
            *temp_buf = '1';
            break;
          case 'f':
            *temp_buf = '0';
            break;
        }
    }
}
