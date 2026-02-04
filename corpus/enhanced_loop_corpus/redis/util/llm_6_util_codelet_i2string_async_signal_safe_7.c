#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp[16];
    for (ix = 0; ix < 16; ++ix) {
        temp[ix] = buf[-ix];
    }
    for (ix = 0; ix < 16; ++ix) {
        switch (temp[ix]) {
          case '0':
            buf[-ix] = 'f';
            break;
          case '1':
            buf[-ix] = 'e';
            break;
          case '2':
            buf[-ix] = 'd';
            break;
          case '3':
            buf[-ix] = 'c';
            break;
          case '4':
            buf[-ix] = 'b';
            break;
          case '5':
            buf[-ix] = 'a';
            break;
          case '6':
            buf[-ix] = '9';
            break;
          case '7':
            buf[-ix] = '8';
            break;
          case '8':
            buf[-ix] = '7';
            break;
          case '9':
            buf[-ix] = '6';
            break;
          case 'a':
            buf[-ix] = '5';
            break;
          case 'b':
            buf[-ix] = '4';
            break;
          case 'c':
            buf[-ix] = '3';
            break;
          case 'd':
            buf[-ix] = '2';
            break;
          case 'e':
            buf[-ix] = '1';
            break;
          case 'f':
            buf[-ix] = '0';
            break;
        }
    }
}
