#include "Folder.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void Folder::deleteItem() {
    if (fs::remove_all(path))
        std::cout << "Folder and contents deleted: " << path << std::endl;
    else
        std::cout << "Failed to delete folder." << std::endl;
}

void Folder::renameItem(const std::string& newName) {
    fs::rename(path, newName);
    std::cout << "Folder renamed to: " << newName << std::endl;
}

size_t Folder::calculateSize() const {
    size_t folderSize = 0;
    for (const auto& entry : fs::recursive_directory_iterator(path))
        if (fs::is_regular_file(entry.path()))
            folderSize += fs::file_size(entry.path());
    return folderSize;
}
