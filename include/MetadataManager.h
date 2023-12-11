#ifndef METADATA_MANAGER_H
#define METADATA_MANAGER_H

#include <string>
#include <map>

#include "EpisodeMetadata.h"

class MetadataManager {
private:
    std::map<size_t, EpisodeMetadata> metadataMap; // Key = episode number

public:
    void addMetadata(size_t i_episodeNumber, const EpisodeMetadata& i_metadata);
    void updateMetadata(size_t i_episodeNumber, const EpisodeMetadata& i_metadata);
    EpisodeMetadata getMetadata(size_t i_episodeNumber) const;
    void removeMetadata(size_t i_episodeNumber);
};

#endif // METADATA_MANAGER_H

