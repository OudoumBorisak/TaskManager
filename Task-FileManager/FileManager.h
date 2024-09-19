#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include "File.h"
#include "RegularFile.h"
#include "Folder.h"

class FileManager {
public:
    void showDiskContent(const std::string& path);
    void createFile(const std::string& path);
    void createFolder(const std::string& path);
    void deleteFile(const std::string& path);
    void deleteFolder(const std::string& path);
    void renameFile(const std::string& oldPath, const std::string& newPath);
    void copyFile(const std::string& source, const std::string& destination);
    void moveFile(const std::string& source, const std::string& destination);
    size_t calculateSize(const std::string& path);
    void searchByMask(const std::string& path, const std::string& mask);
};
