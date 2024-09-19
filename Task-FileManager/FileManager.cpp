#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <regex>

namespace fs = std::filesystem;

void FileManager::showDiskContent(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}

void FileManager::createFile(const std::string& path) {
    std::ofstream file(path);
    if (file.is_open()) {
        file.close();
        std::cout << "File created: " << path << std::endl;
    }
    else {
        std::cout << "Failed to create file." << std::endl;
    }
}

void FileManager::createFolder(const std::string& path) {
    if (fs::create_directory(path))
        std::cout << "Folder created: " << path << std::endl;
    else
        std::cout << "Failed to create folder." << std::endl;
}

void FileManager::deleteFile(const std::string& path) {
    if (fs::remove(path))
        std::cout << "File deleted: " << path << std::endl;
    else
        std::cout << "Failed to delete file." << std::endl;
}

void FileManager::deleteFolder(const std::string& path) {
    if (fs::remove_all(path))
        std::cout << "Folder and contents deleted: " << path << std::endl;
    else
        std::cout << "Failed to delete folder." << std::endl;
}

void FileManager::renameFile(const std::string& oldPath, const std::string& newPath) {
    fs::rename(oldPath, newPath);
    std::cout << "Renamed from " << oldPath << " to " << newPath << std::endl;
}

void FileManager::copyFile(const std::string& source, const std::string& destination) {
    fs::copy(source, destination);
    std::cout << "File copied to: " << destination << std::endl;
}

void FileManager::moveFile(const std::string& source, const std::string& destination) {
    fs::rename(source, destination);
    std::cout << "File moved to: " << destination << std::endl;
}

size_t FileManager::calculateSize(const std::string& path) {
    if (fs::is_regular_file(path))
        return fs::file_size(path);

    size_t folder_size = 0;
    for (const auto& entry : fs::recursive_directory_iterator(path))
        if (fs::is_regular_file(entry.path()))
            folder_size += fs::file_size(entry.path());

    return folder_size;
}

void FileManager::searchByMask(const std::string& path, const std::string& mask) {
    std::regex maskPattern(mask);
    for (const auto& entry : fs::recursive_directory_iterator(path))
        if (std::regex_match(entry.path().filename().string(), maskPattern))
            std::cout << entry.path() << std::endl;
}
