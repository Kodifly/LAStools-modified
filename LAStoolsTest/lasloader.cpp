#include <iostream>
#include "lasreader.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <LAS file>" << std::endl;
        return 1;
    }

    const char* lasFilePath = argv[1];
    LASreadOpener lasreadopener;
    lasreadopener.set_file_name(lasFilePath);
    LASreader* lasReader = lasreadopener.open();
    
    if (!lasReader) {
        std::cerr << "Error opening LAS file" << std::endl;
        return 1;
    }

    while (lasReader->read_point()) {
        std::cout << "Point: ("
                  << lasReader->get_x() << ", "
                  << lasReader->get_y() << ", "
                  << lasReader->get_z() << ")" << std::endl;
    }

    lasReader->close();
    delete lasReader;
    return 0;
}