#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *inp;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    for (i = 0; i < x_size * y_size; i += 4) {
        offset = i;
        if (offset >= x_size * y_size) break;
        if (*(mid + offset) < 8) {
            uchar* p = in + offset - x_size - 1;
            for (int j = 0; j < 3; j++) {
                *(p + j) = 255;
            }
            p += x_size + 1;
            *p = 255;
            p += 2;
            *p = 255;
            p += x_size - 1;
            for (int j = 0; j < 3; j++) {
                *(p + j) = 255;
            }
        }
        if (offset + 1 < x_size * y_size && *(mid + offset + 1) < 8) {
            uchar* p = in + offset + 1 - x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
            p += x_size + 1; *p = 255;
            p += 2; *p = 255;
            p += x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
        }
        if (offset + 2 < x_size * y_size && *(mid + offset + 2) < 8) {
            uchar* p = in + offset + 2 - x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
            p += x_size + 1; *p = 255;
            p += 2; *p = 255;
            p += x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
        }
        if (offset + 3 < x_size * y_size && *(mid + offset + 3) < 8) {
            uchar* p = in + offset + 3 - x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
            p += x_size + 1; *p = 255;
            p += 2; *p = 255;
            p += x_size - 1;
            for (int j = 0; j < 3; j++) *(p + j) = 255;
        }
    }
}
