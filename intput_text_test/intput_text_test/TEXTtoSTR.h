#pragma once
#include"io.h"
#include<vector>
#include<string>

class TEXTtoSTR {
public:
	std::vector<std::string> texts;//texts”z—ñ‚P‚Â
	std::string path;

	TEXTtoSTR(std::string path);
	~TEXTtoSTR();
	void init(std::string path);
	void final();
private:
	void LoadText(std::string path);
};