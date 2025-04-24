#ifndef DECODE_IMAGE_H
#define DECODE_IMAGE_H

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
  void ToPpm(const std::string& file_name) const;

private:
  std::vector<std::vector<Color>> image_;
  size_t height_;
  size_t width_;
};

#endif
