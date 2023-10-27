#pragma once

#include "data.hpp"

namespace Task
{
    void SerializeToFile(const DataWrapper* data, const char* filePath);

    void DeserializeFromFile(DataWrapper*& data, const char* filePath);
} // namespace Task
