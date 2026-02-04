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
for (i = 0; i < 128; ++i) {
    const struct roundtab *p = roundtab + (i % 64);
    switch (i >> 4) {
      case 0:
        a += (b & c) | (~b & d);
        a += sintab[i % 64];
        break;
      case 1:
        a += (b & d) | (c & ~d);
        a += sintab[i % 64];
        break;
      case 2:
        a += b ^ c ^ d;
        a += sintab[i % 64];
        break;
      case 3:
        a += c ^ (b | ~d);
        a += sintab[i % 64];
        break;
      case 4:
        a += (b & c) | (~b & d);
        a += sintab[i % 64];
        break;
      case 5:
        a += (b & d) | (c & ~d);
        a += sintab[i % 64];
        break;
      case 6:
        a += b ^ c ^ d;
        a += sintab[i % 64];
        break;
      case 7:
        a += c ^ (b | ~d);
        a += sintab[i % 64];
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
