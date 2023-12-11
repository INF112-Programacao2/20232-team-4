#include "MetadataManager.h"

#include <stdexcept>

#include "EpisodeMetadata.h"

void MetadataManager::addMetadata(size_t i_episodeNumber, const EpisodeMetadata& i_metadata) {
    auto result = metadataMap.emplace(i_episodeNumber, i_metadata);
    if (!result.second) {
        throw std::runtime_error("Metadata for this episode already exists.");
    }
}

void MetadataManager::updateMetadata(size_t i_episodeNumber, const EpisodeMetadata& i_metadata) {
    auto it = metadataMap.find(i_episodeNumber);
    if (it != metadataMap.end()) {
        it->second = i_metadata;
    } else {
        throw std::runtime_error("Metadata for this episode does not exist.");
    }
}

EpisodeMetadata MetadataManager::getMetadata(size_t i_episodeNumber) const {
    auto it = metadataMap.find(i_episodeNumber);
    if (it != metadataMap.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Metadata for this episode does not exist.");
    }
}

void MetadataManager::removeMetadata(size_t i_episodeNumber) {
    if (metadataMap.erase(i_episodeNumber) == 0) {
        throw std::runtime_error("Metadata for this episode does not exist.");
    }
}
