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
ssize_t u;
double scale;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec on modern CPU
    u = data_size / sizeof(MagickRealType);
    scale = 1.5;

    kernel = (KernelInfo*)calloc(1, sizeof(KernelInfo));
    if (!kernel) exit(1);

    kernel->width = u;
    kernel->height = 1;
    kernel->x = 0;
    kernel->y = 0;
    kernel->values = (MagickRealType*)calloc(u, sizeof(MagickRealType));
    if (!kernel->values) exit(1);

    kernel->minimum = 0.0;
    kernel->maximum = 0.0;
    kernel->negative_range = 0.0;
    kernel->positive_range = 0.0;
    kernel->angle = 0.0;
    kernel->next = NULL;
    kernel->signature = 0x12345678;
}