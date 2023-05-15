#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

    struct stat file_stat;
    if (stat(filename, &file_stat) != 0) {
        std::cerr << "Error: " << std::strerror(errno) << "\n";
        return 1;
    }

    std::time_t last_modified = file_stat.st_mtime;

    std::string file_type;
    mode_t mode = file_stat.st_mode;
    if (S_ISREG(mode)) {
        if (access(filename, X_OK) == 0) {
            file_type = "Executable";
        } else if (std::strstr(filename, ".cpp") || std::strstr(filename, ".cc") || std::strstr(filename, ".cxx")) {
            file_type = "C++ Source Code";
        } else if (std::strstr(filename, ".c")) {
            file_type = "C Source Code";
        } else if (std::strstr(filename, ".h")) {
            file_type = "C/C++ Header";
        } else if (std::strstr(filename, ".py")) {
            file_type = "Python Source Code";
        } else if (std::strstr(filename, ".sh")) {
            file_type = "Bash Script";
        } else if (std::strstr(filename, ".java")) {
            file_type = "Java source Code";
        } else if (std::strstr(filename, ".js")) {
            file_type = "Javascript Source Code";
        } else if (std::strstr(filename, ".rb")) {
            file_type = "Ruby Source Code";
        } else if (std::strstr(filename, ".pl") || std::strstr(filename, ".pm")) {
            file_type = "Perl Source Code";
        } else if (std::strstr(filename, ".php")) {
            file_type = "PHP Source Code";
        } else if (std::strstr(filename, ".swift")) {
            file_type = "Swift Source Code";
        } else if (std::strstr(filename, ".kt")) {
            file_type = "Kotlin Source Code";
        } else if (std::strstr(filename, ".rs")) {
            file_type = "Rust Source Code";
        } else if (std::strstr(filename, ".go")) {
            file_type = "Go Source Code";
        } else if (std::strstr(filename, ".ts")) {
            file_type = "Typescript Source Code";
        } else if (std::strstr(filename, ".scala")) {
            file_type = "Scala Source Code";
        } else if (std::strstr(filename, ".lua")) {
            file_type = "Lua Source Code";
        } else if (std::strstr(filename, ".hs")) {
            file_type = "Haskell Source code";
        } else if (std::strstr(filename, ".r")) {
            file_type = "R Source Code";
        } else if (std::strstr(filename, ".m")) {
            file_type = "Matlab Source Code";
        } else if (std::strstr(filename, ".asm") || std::strstr(filename, ".S")) {
            file_type = "Assembly Source Code";
        } else if (std::strstr(filename, ".txt")) {
            file_type = "Text File";
        } else if (std::strstr(filename, ".pdf")) {
            file_type = "Image File";
        } else if (std::strstr(filename, ".jpg") || std::strstr(filename, ".jpeg")) {
            file_type = "Image File";
        } else if (std::strstr(filename, ".doc") || std::strstr(filename, ".docx")) {
            file_type = "Microsoft Word Document";
        } else if (std::strstr(filename, ".xls") || std::strstr(filename, ".xlsx")) {
            file_type = "Microsoft Excel Spreadsheet";
        } else if (std::strstr(filename, ".ppt") || std::strstr(filename, ".pptx")) {
            file_type = "Microsoft Powerpoint Presentation";
        } else if (std::strstr(filename, ".gif")) {
            file_type = "Graphics Interchange Format";
        } else if (std::strstr(filename, ".mp3")) {
            file_type = "Audio file";
        } else if (std::strstr(filename, ".mp4")) {
            file_type = "Video File";
        } else if (std::strstr(filename, ".mkv")) {
            file_type = "Video File";
        } else if (std::strstr(filename, ".zip")) {
            file_type = "Zip Archive File";
        } else if (std::strstr(filename, ".tar")) {
            file_type = "Tape Archive File";
        } else if (std::strstr(filename, ".exe")) {
            file_type = "Windows Executable File";
        } else if (std::strstr(filename, ".deb")) {
            file_type = "Debian/Ubuntu Package file";
        } else if (std::strstr(filename, ".rpm")) {
            file_type = "Red Hat/Fedora Package File";
        } else if (std::strstr(filename, ".iso")) {
            file_type = "CD/DVD Disk Image File";
        } else if (std::strstr(filename, ".so")) {
            file_type = "Linux Shared Object Library File";
        } else {
            file_type = "Regular File";
        }
    } else if (S_ISDIR(mode)) {
        file_type = "Directory";
    } else if (S_ISLNK(mode)) {
        file_type = "Symbolic Link";
    } else if (S_ISCHR(mode)) {
        file_type = "Character Device";
    } else if (S_ISBLK(mode)) {
        file_type = "Block Device";
    } else if (S_ISFIFO(mode)) {
        file_type = "Named Pipe (FIFO)";
    } else if (S_ISSOCK(mode)) {
        file_type = "Socket";
    } else {
        file_type = "Unknown";
    }

    std::string permissions_string;
    permissions_string += ((mode & S_IRUSR) != 0) ? "r" : "-";
    permissions_string += ((mode & S_IWUSR) != 0) ? "w" : "-";
    permissions_string += ((mode & S_IXUSR) != 0) ? "x" : "-";
    permissions_string += ((mode & S_IRGRP) != 0) ? "r" : "-";
    permissions_string += ((mode & S_IWGRP) != 0) ? "w" : "-";
    permissions_string += ((mode & S_IXGRP) != 0) ? "x" : "-";
    permissions_string += ((mode & S_IROTH) != 0) ? "r" : "-";
    permissions_string += ((mode & S_IWOTH) != 0) ? "w" : "-";
    permissions_string += ((mode & S_IXOTH) != 0) ? "x" : "-";

    std::cout << "File Name: \033[0;32m" << filename << "\033[0m\n";
    std::cout << "File Size: \033[0;33m" << size << " bytes\033[0m\n";
    std::cout << "Last Modified: \033[1;36m" << std::asctime(std::localtime(&last_modified));
    std::cout << "\033[0mFile Type: \033[1;32m" << file_type << "\033[0m\n";
    std::cout << "File Permissions: \033[0;31m" << permissions_string << "\033[0m\n";

    file.close();

    return 0;
}

