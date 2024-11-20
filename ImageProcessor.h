#pragma once
#include <memory>
#include "./image.h"

class ImageProcessor {
 public:
    virtual ~ImageProcessor() = default;

    // Method to process the whole image
    virtual int ProcessWholeImage() = 0;

    // Method to process a single pixel
    virtual int ProcessPixel(int x, int y) = 0;
};

