#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; ++outer) {
        for (ix = 0; ix < 8; ++ix, --buf) {
            switch (*buf) {
              case '0':
                *buf = 'f';
                break;
              case '1':
                *buf = 'e';
                break;
              case '2':
                *buf = 'd';
                break;
              case '3':
                *buf = 'c';
                break;
              case '4':
                *buf = 'b';
                break;
              case '5':
                *buf = 'a';
                break;
              case '6':
                *buf = '9';
                break;
              case '7':
                *buf = '8';
                break;
              case '8':
                *buf = '7';
                break;
              case '9':
                *buf = '6';
                break;
              case 'a':
                *buf = '5';
                break;
              case 'b':
                *buf = '4';
                break;
              case 'c':
                *buf = '3';
                break;
              case 'd':
                *buf = '2';
                break;
              case 'e':
                *buf = '1';
                break;
              case 'f':
                *buf = '0';
                break;
            }
        }
    }
}
