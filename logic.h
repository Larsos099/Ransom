#include "includes.h"
using namespace std; using namespace CryptoPP; namespace fs = std::filesystem;
namespace logic{
    std::string getUnixMs(){ // Gets time in Unix Milliseconds
    auto now = chrono::system_clock::now(); // Gets current time
    auto duration = now.time_since_epoch(); // Gets time difference between now and the epoch
    auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count(); // Casts the difference to milliseconds
    std::string milliseconds = std::to_string(ms); // Conversion to string
    return milliseconds;
}
    void collect_files(const fs::path& path, std::vector<fs::path>& file_paths) {
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(entry)) {
                file_paths.push_back(entry.path());
            }
        }
    } else {
        std::cerr << "Path does not exist or is not a directory." << std::endl;
    }
}
}
