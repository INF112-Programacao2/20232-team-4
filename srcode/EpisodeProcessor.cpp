#include "EpisodeProcessor.h"

// Constructor
EpisodeProcessor::EpisodeProcessor(std::filesystem::path i_framesDir, double i_targetFPS)
    : framesDir(i_framesDir), targetFPS(i_targetFPS), saver(i_framesDir), episodeIndex(0) {
}

void EpisodeProcessor::addEpisode(const std::filesystem::path& i_episodePath, std::string i_episodeTitle) {
    // Supported video file extensions
    std::vector<std::string> SUPPORTED_VIDEO_EXTENSIONS = {".mp4", ".avi", ".mkv"};
    
    // Check if the file is regular and has a supported extension
    if (std::filesystem::is_regular_file(i_episodePath) && 
        std::find(SUPPORTED_VIDEO_EXTENSIONS.begin(), SUPPORTED_VIDEO_EXTENSIONS.end(), i_episodePath.extension()) != SUPPORTED_VIDEO_EXTENSIONS.end()) {
        episodeQueue.push_back(i_episodePath);
        episodeTitles.push_back(i_episodePath);
    }
}

void EpisodeProcessor::processEpisode() {
    reader.openEpisode(episodeQueue[episodeIndex]); // Open the video file using EpisodeReader
    EpisodeMetadata metadata = reader.getMetadata();
    metadata.title = episodeTitles[episodeIndex];
    mngr.addMetadata((episodeIndex + 1), metadata); // Key is episode number (index + 1)

    int frameInterval = static_cast<int>(std::ceil(metadata.fps / targetFPS));
    int frameIndex = 0;
    cv::Mat frame;

    while (true) {
        frame = reader.getFrame(frameIndex * frameInterval);
        if (frame.empty()) {
            break; // Break the loop if no frame is returned or if there's an error
        }

        saver.saveFrame(frame, episodeIndex, frameIndex); // Saves frame
        frameIndex++;
    }

    episodeIndex++; // Move to the next episode
}
