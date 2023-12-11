#ifndef EPISODE_READER_H
#define EPISODE_READER_H

#include <opencv2/opencv.hpp>
#include <filesystem>

#include "EpisodeMetadata.h"

class EpisodeReader {
private:
    std::filesystem::path episodePath;
    cv::VideoCapture episodeCap;

public:
	// Constructor
    EpisodeReader();

    void openEpisode(const std::filesystem::path i_episodePath);
    
    double getDuration(); // In seconds
    double getFPS();
	EpisodeMetadata getMetadata();
    cv::Mat getFrame(int i_frameNumber);
    
};

#endif // EPISODE_READER_H

