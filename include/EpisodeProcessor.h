#ifndef EPISODE_PROCESSOR_H
#define EPISODE_PROCESSOR_H

#include <filesystem>
#include <vector>

#include "EpisodeMetadata.h"
#include "MetadataManager.h"
#include "EpisodeReader.h"
#include "FrameSaver.h"

// Class to process video episodes from a directory
class EpisodeProcessor {
private:
    std::vector<std::filesystem::path> episodeQueue;
    std::vector<std::string> episodeTitles;
    
    std::filesystem::path episodesDir;
    std::filesystem::path framesDir;
    
    MetadataManager mngr;
    EpisodeReader reader;
    FrameSaver saver;
    
	size_t episodeIndex;
    double targetFPS; // Set FPS, irrespective of the episodes' original frame rates.
    
public:
	// Constructor
    EpisodeProcessor(std::filesystem::path i_framesDir, double i_targetFPS);
    
    void processEpisode();
    void addEpisode(const std::filesystem::path& i_episodeQueue, std::string i_episodeTitle);
};

#endif // EPISODE_PROCESSOR_H

