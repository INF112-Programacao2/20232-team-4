#include "EpisodeReader.h"

#include <stdexcept>

// Constructor
EpisodeReader::EpisodeReader() {}

void EpisodeReader::openEpisode(const std::filesystem::path i_episodePath) {
    episodePath = i_episodePath;
    episodeCap.open(episodePath);
    if (!episodeCap.isOpened()) {
        throw std::runtime_error("Unable to open episode file: " + i_episodePath.string());
    }
}

double EpisodeReader::getDuration() {
    return episodeCap.get(cv::CAP_PROP_FRAME_COUNT) / episodeCap.get(cv::CAP_PROP_FPS);
}

double EpisodeReader::getFPS() {
   return episodeCap.get(cv::CAP_PROP_FPS);
}

EpisodeMetadata EpisodeReader::getMetadata() {
    EpisodeMetadata metadata;
    metadata.duration = this->getDuration();
    metadata.fps = this->getFPS();
    
    return metadata;
}

cv::Mat EpisodeReader::getFrame(int i_frameNumber) {
    // Set the position of the next video frame to be captured
    episodeCap.set(cv::CAP_PROP_POS_FRAMES, i_frameNumber);

    cv::Mat frame;
    // Capture the frame
    if (!episodeCap.read(frame)) {
        frame.empty();
    }

    return frame;
}

