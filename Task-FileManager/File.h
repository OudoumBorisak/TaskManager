#pragma once
#include <string>
#include <filesystem>

class File {
protected:
    std::string name;
    std::string path;

public:
    virtual void deleteItem() = 0;
    virtual void renameItem(const std::string& newName) = 0;
    virtual size_t calculateSize() const = 0;
};
