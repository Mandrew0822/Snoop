#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <map>
#include "include/json.hpp"

// Function to get the file type based on the file extension
std::string getFileType(const std::string& filename) {
    // Import json data from /etc/snoop/data.json
    std::ifstream json_file("/etc/snoop/data.json");
    nlohmann::json jsondata = nlohmann::json::parse(json_file);

    std::size_t dotIndex = filename.find_last_of(".");
    // If extension found
    if (dotIndex != std::string::npos) {
        std::string extension = filename.substr(dotIndex);
        try{
            return jsondata[extension];
        }
        catch(...){
            return "Regular File";
        }
    }

    return "Regular File";
}

// Function to get the string representation of file permissions
std::string getPermissionString(mode_t mode) {
    std::string permissionString;

    // Owner permissions
    permissionString += (mode & S_IRUSR) ? "r" : "-";
    permissionString += (mode & S_IWUSR) ? "w" : "-";
    permissionString += (mode & S_IXUSR) ? "x" : "-";

    // Group permissions
    permissionString += (mode & S_IRGRP) ? "r" : "-";
    permissionString += (mode & S_IWGRP) ? "w" : "-";
    permissionString += (mode & S_IXGRP) ? "x" : "-";

    // Others permissions
    permissionString += (mode & S_IROTH) ? "r" : "-";
    permissionString += (mode & S_IWOTH) ? "w" : "-";
    permissionString += (mode & S_IXOTH) ? "x" : "-";

    return permissionString;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [filename]\n";
        return 1;
    }

    const char* filename = argv[1];

    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Error: " << std::strerror(errno) << "\n";
        return 1;
    }

    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();

    struct stat fileStat;
    if (stat(filename, &fileStat) != 0) {
        std::cerr << "Error: " << std::strerror(errno) << "\n";
        return 1;
    }

    std::time_t lastModified = fileStat.st_mtime;

    std::string fileType = getFileType(filename);
    std::string permissionString = getPermissionString(fileStat.st_mode);

    std::cout << "File Name: \033[0;32m" << filename << "\033[0m\n";
    std::cout << "File Size: \033[0;33m" << size << " bytes\033[0m\n";
    std::cout << "Last Modified: \033[1;36m" << std::asctime(std::localtime(&lastModified));
    std::cout << "\033[0mFile Type: \033[1;32m" << fileType << "\033[0m\n";
    std::cout << "File Permissions: \033[0;31m" << permissionString << "\033[0m\n";

    file.close();

    return 0;
}
