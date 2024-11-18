#pragma once
#include <memory>
#include <utility>
#include "./image.h"
#include "./imageProcessor.h"

class ImageBrightener : public ImageProcessor {
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage)
        : m_inputImage(std::move(inputImage)) {}

    int ProcessWholeImage() override {
        int attenuatedPixelCount = 0;
        for (int x = 0; x < m_inputImage->GetRows(); ++x) {
            for (int y = 0; y < m_inputImage->GetColumns(); ++y) {
                attenuatedPixelCount += ProcessPixel(x, y);
            }
        }
        return attenuatedPixelCount;
    }

    int ProcessPixel(int x, int y) override {
        uint8_t pixel = m_inputImage->GetPixel(x, y);
        if (pixel > (255 - 25)) {
            m_inputImage->SetPixel(x, y, 255);  // Clamp to max value (255)
            return 1;  // Attenuated pixel
        } else {
            m_inputImage->SetPixel(x, y, pixel + 25);  // Increase brightness by 25
            return 0;  // Non-attenuated pixel
        }
    }

 private:
    std::shared_ptr<Image> m_inputImage;
};
