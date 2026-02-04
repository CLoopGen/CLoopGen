#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern  WORD k[64];
extern WORD a;
extern WORD b;
extern WORD c;
extern WORD d;
extern WORD e;
extern WORD f;
extern WORD g;
extern WORD h;
extern WORD i;
extern WORD t1;
extern WORD t2;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; ++i) {
    t1 = h + ((((e) >> (7)) | ((e) << (32 - (7)))) ^ (((e) >> (13)) | ((e) << (32 - (13))))) + (((e) & (f)) ^ (~(e) & (g))) + k[i] + m[i];
    t2 = ((((a) >> (3)) | ((a) << (32 - (3)))) ^ (((a) >> (17)) | ((a) << (32 - (17))))) + ((a) & (b));
    h = g;
    g = f;
    f = e;
    e = d + t1;
    d = c;
    c = b;
    b = a;
    a = t1 + t2;
}
}
