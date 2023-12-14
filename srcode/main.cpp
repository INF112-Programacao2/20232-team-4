#include <iostream>
#include <filesystem>

#include "EpisodeProcessor.h"

int main() {
    std::filesystem::path framesDir;
    std::cout << "Enter directory frames are to be extracted to: ";
    std::cin >> framesDir;

    if (!std::filesystem::is_directory(framesDir)) {
        std::cerr << "Invalid directory" << std::endl;
        return -1;
    }

    EpisodeProcessor processor(framesDir, 4);

    std::string episodePath, episodeTitle;
    while (true) {
        std::cout << "Enter episode file path (or 'exit' to finish): ";
        std::cin >> episodePath;
        
        std::cout << "Enter episode title (or 'exit' to finish): ";
        std::cin >> episodeTitle;

        if (episodePath == "exit" || episodeTitle == "exit") break;

        processor.addEpisode(episodePath, episodeTitle);
        processor.processEpisode();
    }

    return 0;
}
