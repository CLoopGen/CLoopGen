#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    UndefinedColorspace,
    CMYColorspace,
    CMYKColorspace,
    GRAYColorspace,
    HCLColorspace,
    HCLpColorspace,
    HSBColorspace,
    HSIColorspace,
    HSLColorspace,
    HSVColorspace,
    HWBColorspace,
    LabColorspace,
    LCHColorspace,
    LCHabColorspace,
    LCHuvColorspace,
    LogColorspace,
    LMSColorspace,
    LuvColorspace,
    OHTAColorspace,
    Rec601YCbCrColorspace,
    Rec709YCbCrColorspace,
    RGBColorspace,
    scRGBColorspace,
    sRGBColorspace,
    TransparentColorspace,
    xyYColorspace,
    XYZColorspace,
    YCbCrColorspace,
    YCCColorspace,
    YDbDrColorspace,
    YIQColorspace,
    YPbPrColorspace,
    YUVColorspace,
    LinearGRAYColorspace,
    JzazbzColorspace,
    DisplayP3Colorspace,
    Adobe98Colorspace,
    ProPhotoColorspace,
    OklabColorspace,
    OklchColorspace,
    CAT02LMSColorspace
} ColorspaceType;

typedef enum {
    UndefinedPixelTrait = 0,
    CopyPixelTrait = 1,
    UpdatePixelTrait = 2,
    BlendPixelTrait = 4
} PixelTrait;

typedef unsigned long long MagickSizeType;

typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

typedef struct _PixelInfo {
    ClassType storage_class;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    double fuzz;
    size_t depth;
    MagickSizeType count;
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType black;
    MagickRealType alpha;
    MagickRealType index;
} PixelInfo;

double census[4];
double edge_census;
PixelInfo background[4];
PixelInfo edge_background;
ssize_t i;

void init_vars() {
    for (i = 0; i < 4; i++) {
        census[i] = (double)(i * 10 + 5);
        background[i].storage_class = (i % 2) ? DirectClass : PseudoClass;
        background[i].colorspace = RGBColorspace + (i % 3);
        background[i].alpha_trait = (i == 0) ? UndefinedPixelTrait : 
                                   (i == 1) ? CopyPixelTrait :
                                   (i == 2) ? UpdatePixelTrait : BlendPixelTrait;
        background[i].fuzz = i * 0.1;
        background[i].depth = 8 + i * 4;
        background[i].count = (MagickSizeType)(1000ULL + i * 100);
        background[i].red = 0.1 + i * 0.2;
        background[i].green = 0.2 + i * 0.15;
        background[i].blue = 0.3 + i * 0.1;
        background[i].black = (i > 2) ? 0.5 : 0.0;
        background[i].alpha = 1.0 - i * 0.1;
        background[i].index = i * 100.0;
    }
    edge_census = 0.0;
    edge_background = background[0];
}