#include "serializer.hpp"
#include <fstream>
#include <unordered_map>

namespace Task
{
    void SerializeToFile(const DataWrapper* data, const char* filePath)
    {
        
        std::ofstream myFile(filePath, std::ios::binary);
        std::unordered_map<const uint8_t*, size_t> bufferMap;
        size_t index = 0;

        myFile.write(reinterpret_cast<const char*>(&data->numBuffers), sizeof(data->numBuffers)); //we are casting our pointer from type size_t to const char* because write() needs it 
        myFile.write(reinterpret_cast<const char*>(&data->numData), sizeof(data->numData)); //same but with numData

        for(size_t i = 0; i < data->numBuffers; i++) {
           // checking if buffer already writed
            auto it = bufferMap.find(data->buffers[i].data);
            if (it == bufferMap.end()) {
                // if it is new buffer 
                bufferMap[data->buffers[i].data] = index++;
                myFile.write(reinterpret_cast<const char*>(&data->buffers[i].size), sizeof(data->buffers[i].size));
                myFile.write(reinterpret_cast<const char*>(data->buffers[i].data), data->buffers[i].size);
            } else {
                // if it already existed
                size_t existingIndex = it->second;
                size_t size = 0;
                myFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
                myFile.write(reinterpret_cast<const char*>(&existingIndex), sizeof(existingIndex));
            }
        }

        for(size_t i = 0; i < data->numData; ++i)
        {
            myFile.write(reinterpret_cast<const char*>(&data->data[i].value), sizeof(data->data[i].value));
        }

    }

    void DeserializeFromFile(DataWrapper*& data, const char* filePath)
    {
        std::ifstream myFile(filePath, std::ios::binary);
        std::unordered_map<size_t, uint8_t*> indexToBufferMap;
        size_t index = 0;

        data = new DataWrapper();

        myFile.read(reinterpret_cast<char*>(&data->numBuffers), sizeof(data->numBuffers));
        myFile.read(reinterpret_cast<char*>(&data->numData), sizeof(data->numData));

        data->buffers = new Buffer[data->numBuffers];

        for(size_t i = 0; i < data->numBuffers; i++) {
            myFile.read(reinterpret_cast<char*>(&data->buffers[i].size), sizeof(data->buffers[i].size));
            
            if(data->buffers[i].size > 0) {
                // new buffer, reading data
                data->buffers[i].data = new uint8_t[data->buffers[i].size];
                myFile.read(reinterpret_cast<char *>(data->buffers[i].data), data->buffers[i].size);
                indexToBufferMap[index++] = data->buffers[i].data;
            } else {
                // buffer ist reference, we load an index  and set previously loaded data 
                size_t existingIndex;
                myFile.read(reinterpret_cast<char *>(&existingIndex), sizeof(existingIndex));
                data->buffers[i].data = indexToBufferMap[existingIndex];
            }
        }    

        data->data = new Data[data->numData];

        for(size_t i = 0; i < data->numData; i++) {
            myFile.read(reinterpret_cast<char *>(&data->data[i].value), sizeof(data->data[i].value));
        }

    }
} // namespace Task
