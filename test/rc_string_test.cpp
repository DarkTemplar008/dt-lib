#include <chrono>
#include <iostream>

#include "../rc_string.hpp"

int main(int argc, char* argv[]) {
	dt::base::String str[10];
	for (int i = 0; i < 10; ++i) {
		str[i] = dt::base::String(i);
	}
	std::string pstr[10];
	for (int i = 0; i < 10; ++i) {
		pstr[i] = str[i];
	}

	int compare_count = 100000000;

	auto now = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < compare_count; ++i) {
		if ( str[i%10] == str[(i+1)%10]) {
			break;
		}
        bool test = str[i%10] != str[(i+1)%10];
	}
	std::cout << "begin:" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-now).count() << std::endl;

	now = std::chrono::high_resolution_clock::now();
	for (int i= 0; i < compare_count; ++i) {
		if ( pstr[i%10] == pstr[(i+1)%10]) {
			break;
		}
        bool test = pstr[i%10] != pstr[(i+1)%10];
	}
	std::cout << "end  :" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-now).count() << std::endl;
	return 0;
}

/*
begin:4571
end  :1947
 */