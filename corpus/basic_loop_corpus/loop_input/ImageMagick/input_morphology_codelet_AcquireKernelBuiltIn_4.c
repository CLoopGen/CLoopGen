#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedKernel,
    UnityKernel,
    GaussianKernel,
    DoGKernel,
    LoGKernel,
    BlurKernel,
    CometKernel,
    BinomialKernel,
    LaplacianKernel,
    SobelKernel,
    FreiChenKernel,
    RobertsKernel,
    PrewittKernel,
    CompassKernel,
    KirschKernel,
    DiamondKernel,
    SquareKernel,
    RectangleKernel,
    OctagonKernel,
    DiskKernel,
    PlusKernel,
    CrossKernel,
    RingKernel,
    PeaksKernel,
    EdgesKernel,
    CornersKernel,
    DiagonalsKernel,
    LineEndsKernel,
    LineJunctionsKernel,
    RidgesKernel,
    ConvexHullKernel,
    ThinSEKernel,
    SkeletonKernel,
    ChebyshevKernel,
    ManhattanKernel,
    OctagonalKernel,
    EuclideanKernel,
    UserDefinedKernel
} KernelInfoType;

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _KernelInfo {
    KernelInfoType type;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    MagickRealType *values;
    double minimum;
    double maximum;
    double negative_range;
    double positive_range;
    double angle;
    struct _KernelInfo *next;
    size_t signature;
} KernelInfo;

KernelInfo *kernel;
ssize_t i;

void init_vars() {
    const size_t data_size = 16777216; // ~134 MB of data (16M doubles)

    kernel = (KernelInfo*)calloc(1, sizeof(KernelInfo));
    kernel->width = data_size;
    kernel->height = 1;
    kernel->x = 0;
    kernel->y = 0;
    kernel->type = UnityKernel;
    kernel->minimum = 0.0;
    kernel->maximum = 0.0;
    kernel->negative_range = 0.0;
    kernel->positive_range = 0.0;
    kernel->angle = 0.0;
    kernel->next = NULL;
    kernel->signature = 0x12345678;

    kernel->values = (MagickRealType*)malloc(data_size * sizeof(MagickRealType));
    if (!kernel->values) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        kernel->values[idx] = 1.0;
    }
}