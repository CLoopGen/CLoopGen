#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};


extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing 4 values per iteration to reduce trip count and increase arithmetic density
    UV v;
    for (v = 0; v < 256; v += 4) {
        UV vals[4] = {v, v+1, v+2, v+3};
        for (int i = 0; i < 4; ++i) {
            UV value = vals[i];
            if (value >= 256) continue;

            int cond1 = ((value) >= 'A' && (value) <= 'Z');
            int cond2 = ((value) >= 'a' && (value) <= 'z');
            int cond3 = ((value) >= '0' && (value) <= '9');
            int cond4 = (value) == '_';
            int cond5 = ((value) >= 33 && (value) <= 47);
            int cond6 = ((value) >= 58 && (value) <= 64);
            int cond7 = ((value) >= 91 && (value) <= 96);
            int cond8 = ((value) >= 123 && (value) <= 126);

            int alpha_num = cond1 || cond2 || cond3 || cond4;
            int punct = cond5 || cond6 || cond7 || cond8;

            if (!(alpha_num || punct)) {
                UV idx = (value >> 3) & 31;
                U8 mask = (U8)(1 << (value & 7));
                ((((struct regnode_charclass *)(ret))->bitmap)[idx]) |= mask;
            }
        }
    }
}
