#pragma once
#include <cstdint>
#include <memory>
#include <stdexcept>

class Image {
 public:
    Image(uint16_t rows, uint16_t columns) : m_rows(rows), m_columns(columns) {
        if (rows > 1024 || columns > 1024) {
            throw std::invalid_argument("Image dimensions exceed the 1024x1024 limit.");
        }
        m_pixels =
            std::make_unique<uint8_t[]>(static_cast<size_t>(rows) * static_cast<size_t>(columns));
    }

    uint8_t GetPixel(uint16_t x, uint16_t y) const {
        if (x >= m_rows || y >= m_columns) {
            throw std::out_of_range("Pixel coordinates are out of bounds.");
        }
        return m_pixels[static_cast<size_t>(x) * static_cast<size_t>(m_columns) + y];
    }

    void SetPixel(uint16_t x, uint16_t y, uint8_t value) {
        if (x >= m_rows || y >= m_columns) {
            throw std::out_of_range("Pixel coordinates are out of bounds.");
        }
        m_pixels[static_cast<size_t>(x) * static_cast<size_t>(m_columns) + y] = value;
    }

    bool IsValid() const {
        return m_rows <= 1024 && m_columns <= 1024;
    }

    uint16_t GetRows() const { return m_rows; }
    uint16_t GetColumns() const { return m_columns; }

 private:
    const uint16_t m_rows;
    const uint16_t m_columns;
    std::unique_ptr<uint8_t[]> m_pixels;  // stores the pixel data
};
