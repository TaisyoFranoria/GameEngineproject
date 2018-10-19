#include"io.h"
#include"TEXTtoSTR.h"

int main() {

	TEXTtoSTR* ts = new TEXTtoSTR("text.txt");

	for (int i = 0, n = (signed)ts->texts.size(); i < n; i++) {
		std::cout << ts->texts[i] << std::endl;
	}

	return 0;
}