#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern const DES_LONG DES_SPtrans[8][64];
extern DES_LONG l;
extern DES_LONG r;
extern DES_LONG t;
extern DES_LONG u;
extern DES_LONG *s;
extern int j;
extern DES_LONG E0;
extern DES_LONG E1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 25; j++) {
    DES_LONG t_local, u_local;
    DES_LONG l_prev = l, r_prev = r;

    // Introduce local copies to break some WAW and WAR hazards
    // and reorganize computation to modify data flow

    {
        t_local = r_prev ^ (r_prev >> 16L);
        u_local = t_local & E0;
        t_local &= E1;
        DES_LONG tmp = (u_local << 16);
        u_local ^= r_prev ^ s[0];
        u_local ^= tmp;
        tmp = (t_local << 16);
        t_local ^= r_prev ^ s[1];
        t_local ^= tmp;

        t_local = ({
            register unsigned int ret;
            asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t_local) : "cc");
            ret;
        });

        l = r_prev ^ DES_SPtrans[0][(u_local >> 2L) & 63] ^
                     DES_SPtrans[2][(u_local >> 10L) & 63] ^
                     DES_SPtrans[4][(u_local >> 18L) & 63] ^
                     DES_SPtrans[6][(u_local >> 26L) & 63] ^
                     DES_SPtrans[1][(t_local >> 2L) & 63] ^
                     DES_SPtrans[3][(t_local >> 10L) & 63] ^
                     DES_SPtrans[5][(t_local >> 18L) & 63] ^
                     DES_SPtrans[7][(t_local >> 26L) & 63];
    }

    {
        t_local = l_prev ^ (l_prev >> 16L);
        u_local = t_local & E0;
        t_local &= E1;
        DES_LONG tmp = (u_local << 16);
        u_local ^= l_prev ^ s[2];
        u_local ^= tmp;
        tmp = (t_local << 16);
        t_local ^= l_prev ^ s[3];
        t_local ^= tmp;

        t_local = ({
            register unsigned int ret;
            asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t_local) : "cc");
            ret;
        });

        r = l_prev ^ DES_SPtrans[0][(u_local >> 2L) & 63] ^
                     DES_SPtrans[2][(u_local >> 10L) & 63] ^
                     DES_SPtrans[4][(u_local >> 18L) & 63] ^
                     DES_SPtrans[6][(u_local >> 26L) & 63] ^
                     DES_SPtrans[1][(t_local >> 2L) & 63] ^
                     DES_SPtrans[3][(t_local >> 10L) & 63] ^
                     DES_SPtrans[5][(t_local >> 18L) & 63] ^
                     DES_SPtrans[7][(t_local >> 26L) & 63];
    }

    // Remaining rounds are collapsed into a single loop-like structure using indexing
    // This introduces loop-carried dependency via index, but reduces redundancy
    for (int k = 4; k < 32; k += 2) {
        if ((k / 2) % 2 == 0) { // Even round: operate on updated 'r'
            t_local = r ^ (r >> 16L);
            u_local = t_local & E0;
            t_local &= E1;
            DES_LONG tmp = (u_local << 16);
            u_local ^= r ^ s[k];
            u_local ^= tmp;
            tmp = (t_local << 16);
            t_local ^= r ^ s[k + 1];
            t_local ^= tmp;

            t_local = ({
                register unsigned int ret;
                asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t_local) : "cc");
                ret;
            });

            l ^= DES_SPtrans[0][(u_local >> 2L) & 63] ^
                  DES_SPtrans[2][(u_local >> 10L) & 63] ^
                  DES_SPtrans[4][(u_local >> 18L) & 63] ^
                  DES_SPtrans[6][(u_local >> 26L) & 63] ^
                  DES_SPtrans[1][(t_local >> 2L) & 63] ^
                  DES_SPtrans[3][(t_local >> 10L) & 63] ^
                  DES_SPtrans[5][(t_local >> 18L) & 63] ^
                  DES_SPtrans[7][(t_local >> 26L) & 63];
        } else { // Odd round: operate on updated 'l'
            t_local = l ^ (l >> 16L);
            u_local = t_local & E0;
            t_local &= E1;
            DES_LONG tmp = (u_local << 16);
            u_local ^= l ^ s[k];
            u_local ^= tmp;
            tmp = (t_local << 16);
            t_local ^= l ^ s[k + 1];
            t_local ^= tmp;

            t_local = ({
                register unsigned int ret;
                asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t_local) : "cc");
                ret;
            });

            r ^= DES_SPtrans[0][(u_local >> 2L) & 63] ^
                  DES_SPtrans[2][(u_local >> 10L) & 63] ^
                  DES_SPtrans[4][(u_local >> 18L) & 63] ^
                  DES_SPtrans[6][(u_local >> 26L) & 63] ^
                  DES_SPtrans[1][(t_local >> 2L) & 63] ^
                  DES_SPtrans[3][(t_local >> 10L) & 63] ^
                  DES_SPtrans[5][(t_local >> 18L) & 63] ^
                  DES_SPtrans[7][(t_local >> 26L) & 63];
        }
    }

    // Final swap preserved
    t = l;
    l = r;
    r = t;
}
}
