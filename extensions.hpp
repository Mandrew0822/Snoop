#ifndef EXTENSIONS_HPP
#define EXTENSIONS_HPP

#include <string>
#include <unordered_map>

// there can be some duplicates
static const std::unordered_map<std::string, std::string> ExtensionMap = {
    {".cpp", "C++ Source Code"},
    {".cc", "C++ Source Code"},
    {".cxx", "C++ Source Code"},
    {".c", "C Source Code"},
    {".h", "C/C++ Header"},
    {".py", "Python Source Code"},
    {".sh", "Bash Script"},
    {".java", "Java Source Code"},
    {".js", "Javascript Source Code"},
    {".rb", "Ruby Source Code"},
    {".pl", "Perl Source Code"},
    {".pm", "Perl Source Code"},
    {".php", "PHP Source Code"},
    {".swift", "Swift Source Code"},
    {".kt", "Kotlin Source Code"},
    {".rs", "Rust Source Code"},
    {".go", "Go Source Code"},
    {".ts", "Typescript Source Code"},
    {".scala", "Scala Source Code"},
    {".lua", "Lua Source Code"},
    {".hs", "Haskell Source code"},
    {".r", "R Source Code"},
    {".m", "Matlab Source Code"},
    {".asm", "Assembly Source Code"},
    {".S", "Assembly Source Code"},
    {".txt", "Text File"},
    {".pdf", "Image File"},
    {".jpg", "Image File"},
    {".jpeg", "Image File"},
    {".doc", "Microsoft Word Document"},
    {".docx", "Microsoft Word Document"},
    {".xls", "Microsoft Excel Spreadsheet"},
    {".xlsx", "Microsoft Excel Spreadsheet"},
    {".ppt", "Microsoft Powerpoint Presentation"},
    {".pptx", "Microsoft Powerpoint Presentation"},
    {".gif", "Graphics Interchange Format"},
    {".mp3", "Audio file"},
    {".mp4", "Video File"},
    {".mkv", "Video File"},
    {".zip", "Zip Archive File"},
    {".tar", "Tape Archive File"},
    {".exe", "Windows Executable File"},
    {".deb", "Debian/Ubuntu Package file"},
    {".rpm", "Red Hat/Fedora Package File"},
    {".iso", "CD/DVD Disk Image File"},
    {".so", "Linux Shared Object Library File"},
    {".odt", "OpenDocument text"},
    {".rtf", "Rich Text Format"},
    {".html", "Hypertext Markup Language"},
    {".xml", "eXtensible Markup Language"},
    {".ods", "OpenDocument Spreadsheet"},
    {".csv", "Comma-Separated Values"},
    {".tsv", "Tab-Separated Values"},
    {".odp", "OpenDocument Presentation"},
    {".bmp", "Bitmap Image"},
    {".tiff", "Tagged Image File Format"},
    {".psd", "Adobe Photoshop Document"},
    {".wav", "Waveform Audio File Format"},
    {".aac", "Advanced Audio Coding"},
    {".flac", "Free Lossless Audio Codec"},
    {".ogg", "Ogg Vorbis"},
    {".midi", "Musical Instrument Digital Interface"},
    {".avi", "Audio Video Interleave"},
    {".mov", "QuickTime Movie"},
    {".wmv", "Windows Media Video"},
    {".flv", "Flash Video"},
    {".rar", "Roshal Archive"},
    {".7z", "7-zip Compressed File"},
    {".bz2", "Bzip2 Compressed File"},
    {".sql", "Structured Query Language"},
    {".db", "Database File"},
    {".accdb", "Microsoft Access Database"},
    {".json", "Javascript Object Notation"},
    {".dll", "Dynamic Link Library"},
    {".apk", "Android Package File"},
    {".ttf", "TrueType Font File"},
    {".otf", "OpenType Font file"},
    {".css", "Cascading Style Sheet"},
    {".scss", "Sass CSS File"},
    {".less", "Less CSS File"},
    {".jsx", "JavaScript XML"},
    {".tsx", "TypeScript XML"},
    {".php", "PHP Script"},
    {".html", "HTML File"},
    {".htm", "HTML File"},
    {".asp", "Active Server Pages"},
    {".aspx", "Active Server Pages"},
    {".jsp", "Java Server Pages"},
    {".cgi", "Common Gateway Interface Script"},
    {".vb", "Visual Basic File"},
    {".cs", "C# Source Code"},
    {".vb", "Visual Basic Source Code"},
    {".vb", "Visual Basic Source Code"},
    {".xml", "XML File"},
    {".svg", "Scalable Vector Graphics"},
    {".yaml", "YAML File"},
    {".cfg", "Configuration File"},
    {".conf", "Configuration File"},
    {".properties", "Properties File"},
    {".bat", "Batch File"},
    {".cmd", "Windows Command Script"},
    {".ps1", "PowerShell Script"},
    {".vbs", "VBScript File"},
    {".log", "Log File"},
    {".csv", "CSV File"},
    {".tsv", "TSV File"},
    {".dat", "Data File"},
    {".bin", "Binary File"},
    {".class", "Java Class File"},
    {".jar", "Java Archive File"},
    {".war", "Web Application Archive"},
    {".ear", "Enterprise Archive"},
    {".dll", "Dynamic Link Library"},
    {".lib", "Library File"},
    {".obj", "Object File"},
    {".o", "Object File"},
    {".a", "Archive File"},
    {".so", "Shared Object File"},
    {".ko", "Kernel Object File"},
    {".apk", "Android Package"},
    {".dmg", "Disk Image"},
    {".iso", "ISO Image"},
    {".img", "Disk Image"},
    {".mdf", "Media Disc Image"},
    {".vhd", "Virtual Hard Disk"},
    {".torrent", "Torrent File"},
    {".eml", "Email Message"},
    {".msg", "Outlook Message File"},
    {".pst", "Outlook Data File"},
    {".ics", "Calendar File"},
    {".vcf", "vCard File"},
    {".zip", "ZIP Archive"},
    {".rar", "RAR Archive"},
    {".7z", "7-Zip Archive"},
    {".tar", "Tar Archive"},
    {".gz", "Gzip Compressed File"},
    {".xz", "XZ Compressed File"},
    {".bz2", "Bzip2 Compressed File"},
    {".lzo", "LZop Compressed File"},
    {".lzma", "LZMA Compressed File"},
    {".z", "Z Compressed File"},
    {".arj", "ARJ Archive"},
    {".cab", "Cabinet File"},
    {".wim", "Windows Imaging Format"},
    {".md", "Markdown File"},
    {".log", "Log File"},
    {".cfg", "Configuration File"},
    {".ini", "Initialization File"},
    {".sh", "Shell Script"},
    {".ps1", "PowerShell Script"},
};

#endif // !EXTENSIONS_HPP