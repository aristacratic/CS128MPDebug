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
  size_t midpoint = width_ / 2;
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < midpoint; w++) {
      size_t opposite = width_ - 1 - w;
      Color temp = image_.at(h).at(w);
      image_.at(h).at(w) = image_.at(h).at(opposite);
      image_.at(h).at(opposite) = temp;
    }
  }
}

void DecodeImage::FlipVertical() {
  size_t midpoint = height_ / 2;
  for (size_t h = 0; h < midpoint; h++) {
    size_t oppposite = height_ - 1 - h;
    for (size_t w = 0; w < width_; w++) {
      Color temp = image_.at(h).at(w);
      image_.at(h).at(w) = image_.at(oppposite).at(w);
      image_.at(oppposite).at(w) = temp;
    }
  }
}

void DecodeImage::InvertColors() {
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < width_; w++) {
      Color& pixel = image_.at(h).at(w);
      int invert_red = kMaxColorValue - pixel.Red();
      int invert_green = kMaxColorValue - pixel.Green();
      int invert_blue = kMaxColorValue - pixel.Blue();
      pixel = Color(invert_red, invert_green, invert_blue);
    }
  }
}

void DecodeImage::BrightenImage(int value) {
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < width_; w++) {
      Color& pixel = image_.at(h).at(w);
      int bright_red = pixel.Red() + value;
      if (bright_red > kMaxColorValue) {
        bright_red = kMaxColorValue;
      }
      int bright_green = pixel.Green() + value;
      if (bright_green > kMaxColorValue) {
        bright_green = kMaxColorValue;
      }
      int bright_blue = pixel.Blue() + value;
      if (bright_blue > kMaxColorValue) {
        bright_blue = kMaxColorValue;
      }
      pixel = Color(bright_red, bright_green, bright_blue);
    }
  }
}

void DecodeImage::DarkenImage(int value) {
  for (size_t h = 0; h < height_; h++) {
    for (size_t w = 0; w < width_; w++) {
      Color& pixel = image_.at(h).at(w);
      int dark_red = pixel.Red() - value;
      if (dark_red < kMinColorValue) {
        dark_red = kMinColorValue;
      }
      int dark_green = pixel.Green() - value;
      if (dark_green < kMinColorValue) {
        dark_green = kMinColorValue;
      }
      int dark_blue = pixel.Blue() - value;
      if (dark_blue < kMinColorValue) {
        dark_blue = kMinColorValue;
      }
      pixel = Color(dark_red, dark_green, dark_blue);
    }
  }
}

void DecodeImage::ToPPM(const std::string& file_name) const {
  std::ofstream ofs{file_name};
  ofs << "P3\n";
  ofs << width_ << " " << height_ << "\n";
  ofs << kMaxColorValue << "\n";
  for (unsigned int h = 0; h < height_; h++) {
    for (unsigned int w = 0; w < width_; w++) {
      if (width_ - 1 == w) {
        ofs << image_.at(h).at(w).Red() << " " << image_.at(h).at(w).Green()
            << " " << image_.at(h).at(w).Blue() << "\n";
      } else {
        ofs << image_.at(h).at(w).Red() << " " << image_.at(h).at(w).Green()
            << " " << image_.at(h).at(w).Blue() << " ";
      }
    }
  }
  ofs.close();
}