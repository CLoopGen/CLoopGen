#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int md5uint;

struct roundtab {
    char k;
    char s;
};


extern  md5uint sintab[64];
extern  struct roundtab roundtab[64];
extern md5uint a;
extern md5uint b;
extern md5uint c;
extern md5uint d;
extern md5uint t;
extern md5uint x[16];
extern  md5uint msk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; ++i) {
    const struct roundtab *p = roundtab + i;
    switch (i >> 4) {
      case 0:
        a += (b & c) | (~b & d);
        a += sintab[i];
        break;
      case 1:
        a += (b & d) | (c & ~d);
        a += sintab[i];
        break;
    }
    a += x[(int)(p->k)];
    a &= msk;
    t = b + ((a << (int)(p->s)) | (a >> (32 - (int)(p->s))));
    a = d;
    d = c;
    c = b;
    b = t;
}
}
