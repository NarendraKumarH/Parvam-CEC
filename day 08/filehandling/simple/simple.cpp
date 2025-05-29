#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outFile(" example.txt");
    if (outFile.is_open())
    {
        outFile << "Hello, File handling!";
        outFile.close();
        std::cout << "Data written to file successfully.\n";
        }
        else
        {
            std::cout << "Unable to open file for writing.\n";
        }
        return 0;
    }


