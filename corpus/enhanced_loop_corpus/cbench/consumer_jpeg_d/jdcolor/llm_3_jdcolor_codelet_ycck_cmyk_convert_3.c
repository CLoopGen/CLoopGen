#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern int y;
extern int cb;
extern int cr;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW ptr0 = inptr0;
    JSAMPROW ptr1 = inptr1;
    JSAMPROW ptr2 = inptr2;
    JSAMPROW ptr3 = inptr3;
    JSAMPROW out = outptr;
    for (col = 0; col < num_cols; col++) {
        y = ((int)(*ptr0++));
        cb = ((int)(*ptr1++));
        cr = ((int)(*ptr2++));
        *out++ = range_limit[255 - (y + Crrtab[cr])];
        *out++ = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
        *out++ = range_limit[255 - (y + Cbbtab[cb])];
        *out++ = *ptr3++;
    }
    outptr = out;
}
