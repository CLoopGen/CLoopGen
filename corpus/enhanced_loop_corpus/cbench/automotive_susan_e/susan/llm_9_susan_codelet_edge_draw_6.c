#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int idx, limit = x_size * y_size;
for (i = 0; i < limit; i++) {
    idx = midp - mid;
    if (*(midp) < 8) {
        *(in + idx) = 0;
        *(in + idx + 1) = (*(midp + 1) < 8) ? 0 : *(in + idx + 1);
        *(in + idx - 1) = (idx > 0 && *(midp - 1) < 8) ? 0 : *(in + idx - 1);
    }
    midp++;
}
}
