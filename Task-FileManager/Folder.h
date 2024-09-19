#pragma once
#include "File.h"
#include <vector>

class Folder : public File {
public:
    void deleteItem() override;
    void renameItem(const std::string& newName) override;
    size_t calculateSize() const override;
};


