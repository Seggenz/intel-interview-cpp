#include <iostream>
#include "data.hpp"
#include "serializer.hpp"

int main(int argc, char** argv)
{
    // TODO: 1. Prepare example data for serialization
    Task::DataWrapper exampleDataWrapper;

    Task::Data exampleData[2] = {{1234}, {5678}};
    Task::Buffer exampleBuffer[2];

    uint8_t buffer1Data[] = {1, 2};
    uint8_t buffer2Data[] = {3, 4};
    exampleBuffer[0].data = buffer1Data;
    exampleBuffer[0].size = sizeof(buffer1Data);
    exampleBuffer[1].data = buffer2Data;
    exampleBuffer[1].size = sizeof(buffer2Data);

    exampleDataWrapper.data = exampleData;
    exampleDataWrapper.numData = 2;
    exampleDataWrapper.buffers = exampleBuffer;
    exampleDataWrapper.numBuffers = 2;

    // TODO: 2. Serialize data to file
    const char* filePath = "example.dat";
    Task::SerializeToFile(&exampleDataWrapper, filePath);

    // exampleDataWrapper.data[0].value = 4321; //changing the data to check if the data verification would fail

    // TODO: 3. Deserialize data from file
    Task::DataWrapper* deserializedDataWrapper = nullptr;
    Task::DeserializeFromFile(deserializedDataWrapper, filePath);
    // TODO: 4. Verify deserialized data is correct
 if(deserializedDataWrapper->numData == exampleDataWrapper.numData)
    {
        for(size_t i = 0; i < deserializedDataWrapper->numData; ++i)
        {
            if(deserializedDataWrapper->data[i].value != exampleDataWrapper.data[i].value)
            {
                std::cout << "Data verification failed!" << std::endl;
                delete deserializedDataWrapper; 
                return 1;
            }
        }
    }
    else
    {
        std::cout << "Data count mismatch!" << std::endl;
        delete deserializedDataWrapper; 
        return 1;
    }

    std::cout << "Data verification successful!" << std::endl;

    delete deserializedDataWrapper;

    return 0;
}
