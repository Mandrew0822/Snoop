#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <map>

// Function to get the file type based on the file extension
std::string getFileType(const std::string& filename) {
    static const std::map<std::string, std::string> extensionMap = {
        { ".cpp", "C++ Source Code" },
        { ".cc", "C++ Source Code" },
        { ".cxx", "C++ Source Code" },
        { ".c", "C Source Code" },
        { ".h", "C/C++ Header" },
        { ".py", "Python Source Code" },
        { ".sh", "Bash Script" },
        { ".java", "Java Source Code" },
        { ".js", "Javascript Source Code" },
        { ".rb", "Ruby Source Code" },
        { ".pl", "Perl Source Code" },
        { ".pm", "Perl Source Code" },
        { ".php", "PHP Source Code" },
        { ".swift", "Swift Source Code" },
        { ".kt", "Kotlin Source Code" },
        { ".rs", "Rust Source Code" },
        { ".go", "Go Source Code" },
        { ".ts", "Typescript Source Code" },
        { ".scala", "Scala Source Code" },
        { ".lua", "Lua Source Code" },
        { ".hs", "Haskell Source code" },
        { ".r", "R Source Code" },
        { ".m", "Matlab Source Code" },
        { ".asm", "Assembly Source Code" },
        { ".S", "Assembly Source Code" },
        { ".txt", "Text File" },
        { ".pdf", "PDF Document" },
        { ".doc", "Microsoft Word Document" },
        { ".docx", "Microsoft Word Document" },
        { ".xls", "Microsoft Excel Spreadsheet" },
        { ".xlsx", "Microsoft Excel Spreadsheet" },
        { ".ppt", "Microsoft PowerPoint Presentation" },
        { ".pptx", "Microsoft PowerPoint Presentation" },
        { ".gif", "Graphics Interchange Format" },
        { ".png", "Portable Network Graphics" },
        { ".jpg", "JPEG Image" },
        { ".jpeg", "JPEG Image" },
        { ".bmp", "Bitmap Image" },
        { ".svg", "Scalable Vector Graphics" },
        { ".mp3", "MP3 Audio" },
        { ".mp4", "MP4 Video" },
        { ".mkv", "Matroska Video" },
        { ".zip", "Zip Archive" },
        { ".tar", "Tape Archive" },
        { ".exe", "Windows Executable File" },
        { ".deb", "Debian/Ubuntu Package File" },
        { ".rpm", "Red Hat/Fedora Package File" },
        { ".iso", "CD/DVD Disk Image" },
        { ".so", "Shared Object Library" },
        { ".odt", "OpenDocument Text" },
        { ".rtf", "Rich Text Format" },
        { ".html", "HTML Document" },
        { ".xml", "XML Document" },
        { ".ods", "OpenDocument Spreadsheet" },
        { ".csv", "Comma-Separated Values" },
        { ".tsv", "Tab-Separated Values" },
        { ".odp", "OpenDocument Presentation" },
        { ".wav", "Waveform Audio File" },
        { ".aac", "Advanced Audio Coding" },
        { ".flac", "Free Lossless Audio Codec" },
        { ".ogg", "Ogg Vorbis" },
        { ".midi", "Musical Instrument Digital Interface" },
        { ".avi", "Audio Video Interleave" },
        { ".mov", "QuickTime Movie" },
        { ".wmv", "Windows Media Video" },
        { ".flv", "Flash Video" },
        { ".rar", "RAR Archive" },
        { ".7z", "7-Zip Compressed File" },
        { ".bz2", "Bzip2 Compressed File" },
        { ".sql", "Structured Query Language" },
        { ".db", "Database File" },
        { ".accdb", "Microsoft Access Database" },
        { ".json", "JavaScript Object Notation" },
        { ".dll", "Dynamic Link Library" },
        { ".apk", "Android Package File" },
        { ".ttf", "TrueType Font File" },
        { ".otf", "OpenType Font File" },
    };
    

    std::size_t dotIndex = filename.find_last_of(".");
    if (dotIndex != std::string::npos) {
        std::string extension = filename.substr(dotIndex);
        auto it = extensionMap.find(extension);
        if (it != extensionMap.end()) {
            return it->second;
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

// Function to check if a file is executable
bool isExecutable(const std::string& filename) {
    return access(filename.c_str(), X_OK) == 0;
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

    std::string filePath = "./" + std::string(filename);
    bool executable = isExecutable(filePath);

    std::time_t lastModified = fileStat.st_mtime;

    std::string fileType = getFileType(filename);
    std::string permissionString = getPermissionString(fileStat.st_mode);

    std::cout << "File Name: \033[0;32m" << filename << "\033[0m\n";
    std::cout << "File Size: \033[0;33m" << size << " bytes\033[0m\n";
    std::cout << "Last Modified: \033[1;36m" << std::asctime(std::localtime(&lastModified));
    std::cout << "\033[0mFile Type: \033[1;32m" << fileType << "\033[0m\n";
    std::cout << "Linux Executable: " << (executable ? "\x1b[1;35mYes\x1b[0m" : "\x1b[1;35mNo\x1b[0m") << "\n";
    std::cout << "File Permissions: \033[0;31m" << permissionString << "\033[0m\n";

    file.close();

    return 0;
}
