/*
 * Copyright (c) 2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * @brief A header file with definition for Intel RealSense Camera
 * @file realsense_camera.h
 */

#ifndef OPENVINO_PIPELINE_LIB_REALSENSE_CAMERA_H
#define OPENVINO_PIPELINE_LIB_REALSENSE_CAMERA_H

#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include "openvino_service/inputs/base_input.h"

namespace Input {
class RealSenseCamera : public BaseInputDevice {
 public:
  bool initialize() override;
  bool initialize(int t) override { return true; };
  bool initialize(size_t width, size_t height) override;
  bool read(cv::Mat *frame) override;
  void config() override;
 private:
  rs2::config cfg_;
  rs2::pipeline pipe_;
  bool first_read_ = true;
};
}

#endif //OPENVINO_PIPELINE_LIB_REALSENSE_CAMERA_H
