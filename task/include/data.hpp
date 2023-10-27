#pragma once

#include <cstdint>

namespace Task
{
    struct Buffer
    {
        uint8_t* data = nullptr;
        size_t   size = 0;
    };

    struct Data
    {
        uint32_t value = 0;
    };

    struct DataWrapper
    {
        Buffer* buffers    = nullptr;
        size_t  numBuffers = 0;

        Data*  data    = nullptr;
        size_t numData = 0;
    };
} // namespace Task
