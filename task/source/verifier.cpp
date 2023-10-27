#include "verifier.hpp"

#include <cstring>

namespace Task
{
    bool Verify(const Task::DataWrapper* wrapper, const Task::DataWrapper* referenceWrapper)
    {
        if (wrapper == referenceWrapper)
            return true;

        if ((wrapper == nullptr && referenceWrapper != nullptr) || (wrapper != nullptr && referenceWrapper == nullptr))
            return false;

        if (wrapper->numBuffers != referenceWrapper->numBuffers)
            return false;

        for (size_t bufferIdx = 0; bufferIdx < wrapper->numBuffers; ++bufferIdx) {
            const auto& buffer          = wrapper->buffers[bufferIdx];
            const auto& referenceBuffer = referenceWrapper->buffers[bufferIdx];
            if (buffer.size != referenceBuffer.size)
                return false;

            if (std::memcmp(buffer.data, referenceWrapper->data, buffer.size) != 0)
                return false;
        }

        if (wrapper->numData != referenceWrapper->numData)
            return false;

        for (size_t dataIdx = 0; dataIdx < wrapper->numData; ++dataIdx) {
            const auto& data          = wrapper->data[dataIdx];
            const auto& referenceData = referenceWrapper->data[dataIdx];

            if (data.value != referenceData.value)
                return false;
        }

        return true;
    }
} // namespace Task
