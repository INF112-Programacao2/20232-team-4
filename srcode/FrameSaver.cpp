#include "FrameSaver.h"

#include <string>
#include <stdexcept>

// Constructor
FrameSaver::FrameSaver(const std::filesystem::path& i_framesDir) : framesDir(i_framesDir) {
    // Ensure the main directory exists
    if (!std::filesystem::exists(framesDir)) {
        std::filesystem::create_directories(framesDir);
    }
}

void FrameSaver::saveFrame(const cv::Mat& i_frame, size_t i_episodeIndex, int i_frameNumber) {
    // Check if the frame is empty
    if (i_frame.empty()) {
        throw std::runtime_error("Attempted to save an empty frame");
    }

    // Construct the subdirectory path
    std::filesystem::path episodeDir = framesDir / std::to_string(i_episodeIndex + 1);

    // Create the subdirectory if it does not exist
    if (!std::filesystem::exists(episodeDir)) {
        std::filesystem::create_directories(episodeDir);
    }

    // Construct the full path for the frame file
    std::filesystem::path framePath = episodeDir / (std::to_string(i_frameNumber) + ".jpg");

    // Save the frame
    if (!cv::imwrite(framePath.string(), i_frame)) {
        throw std::runtime_error("Failed to save the frame: " + framePath.string());
    }
}
