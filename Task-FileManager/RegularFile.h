#pragma once
#include "File.h"

class RegularFile : public File {
public:
    void deleteItem() override;
    void renameItem(const std::string& newName) override;
    size_t calculateSize() const override;
};

