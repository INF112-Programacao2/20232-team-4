#ifndef FRAME_SAVER_H
#define FRAME_SAVER_H

#include <opencv2/opencv.hpp>
#include <filesystem>

class FrameSaver {
private:
    std::filesystem::path framesDir;

public:
	// Constructor
    FrameSaver(const std::filesystem::path& i_framesDir);

    void saveFrame(const cv::Mat& i_frame, size_t i_episodeIndex, int i_frameNumber);
};

#endif // FRAME_SAVER_H

