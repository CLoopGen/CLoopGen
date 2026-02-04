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
for (i = 0; i < 64; ++i) {
    t1 = h + ((((e) >> (6)) | ((e) << (32 - (6)))) ^ (((e) >> (11)) | ((e) << (32 - (11)))) ^ (((e) >> (25)) | ((e) << (32 - (25))))) + (((e) & (f)) ^ (~(e) & (g))) + k[i] + m[i];
    t2 = ((((a) >> (2)) | ((a) << (32 - (2)))) ^ (((a) >> (13)) | ((a) << (32 - (13)))) ^ (((a) >> (22)) | ((a) << (32 - (22))))) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));
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
