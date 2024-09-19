#include "RegularFile.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void RegularFile::deleteItem() {
    if (fs::remove(path))
        std::cout << "File deleted: " << path << std::endl;
    else
        std::cout << "Failed to delete file." << std::endl;
}

void RegularFile::renameItem(const std::string& newName) {
    fs::rename(path, newName);
    std::cout << "File renamed to: " << newName << std::endl;
}

size_t RegularFile::calculateSize() const {
    return fs::file_size(path);
}
