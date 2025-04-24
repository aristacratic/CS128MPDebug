#include "decode_image.hpp"

/*
    Grayscale to RGB Source
    https://www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.601-7-201103-I!!PDF-E.pdf
*/

void DecodeImage::ConvertToGrayscale() {
  double const kRedFactor = 0.299;
  double const kGreenFactor = 0.587;
  double const kBlueFactor = 0.114;
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < width_; w++) {
      Color& pixel = image_.at(h).at(w);
      int luminance = static_cast<int>(pixel.Red() * kRedFactor +
                                       pixel.Green() * kGreenFactor +
                                       pixel.Blue() * kBlueFactor);
      pixel = Color(luminance, luminance, luminance);
    }
  }
}

void DecodeImage::ConvertToRGB() {
  // Cant be undone mathmatically
}

void DecodeImage::FlipHorizontal() {
  size_t midpoint = height_ / 2;
  for (size_t h = 0; h < midpoint; h++) {
    for (size_t w = 0; w < width_; w++) {
      Color& temp = image_.at(h).at(w);
      image_.at(h).at(w) = image_.at(h + midpoint).at(w);
      image_.at(h + midpoint).at(w) = temp;
    }
  }
}

void DecodeImage::FlipVertical() {}

void DecodeImage::InvertColors() {}

void DecodeImage::BrightenImage(int value) { (void)value; }

void DecodeImage::ToPpm(const std::string& file_name) const { (void)file_name; }