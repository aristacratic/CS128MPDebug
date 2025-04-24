#include "decode_image.hpp"

void DecodeImage::ConvertToGrayscale() {
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < width_; w++) {
    }
  }
}

void DecodeImage::ConvertToRGB() {}

void DecodeImage::FlipHorizontal() {}

void DecodeImage::FlipVertical() {}

void DecodeImage::InvertColors() {}

void DecodeImage::BrightenImage(int value) {}

void DecodeImage::ToPpm(const std::string& fileName) const {}