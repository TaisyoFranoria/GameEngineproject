#include"TEXTtoSTR.h"

TEXTtoSTR::TEXTtoSTR(std::string path) {
	init(path);
}

TEXTtoSTR::~TEXTtoSTR() {
	final();
}

void TEXTtoSTR::init(std::string path) {
	LoadText(path);
}

void TEXTtoSTR::final() {

}

void TEXTtoSTR::LoadText(std::string path) {
	std::ifstream ifs(path);
	std::string str;

	if (ifs.fail()) {
		std::cerr << "“Ç‚Ýž‚ÝŽ¸”s" << std::endl;
	}
}

