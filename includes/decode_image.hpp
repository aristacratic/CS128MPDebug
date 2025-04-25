#ifndef DECODE_IMAGE_H
#define DECODE_IMAGE_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "color.hpp"

class DecodeImage {
public:
  void ConvertToGrayscale();
  void ConvertToRGB();
  void InvertColors();
  void FlipHorizontal();
  void FlipVertical();
  void BrightenImage(int value);
  void DarkenImage(int value);
  void ToPPM(const std::string& file_name) const;

private:
  std::vector<std::vector<Color>> image_;
  size_t height_;
  size_t width_;
  int const kMaxColorValue = 255;
  int const kMinColorValue = 0;
};

#endif
