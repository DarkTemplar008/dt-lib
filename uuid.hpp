#ifndef DT_UTIL_UUID_HPP
#define DT_UTIL_UUID_HPP

#include <string>
#include <random>
#include <chrono>

namespace dt {
namespace util {

inline
std::string GenerateUUID() {
	auto hex_to_char = [=](int val) -> char {
		switch(val) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				return '0' + val;
			case 10:
				return 'A';
			case 11:
				return 'B';
			case 12:
				return 'C';
			case 13:
				return 'D';
			case 14:
				return 'E';
			case 15:
				return 'F';
		}
		return ' ';
	};

	std::random_device rd;
	char guid[32];
	for ( int i = 0; i < 4; ++i) {
		std::uint32_t rand_num = rd();
		char* pos = guid + i*sizeof(int)*2;
		for (int j = 0; j < sizeof(int)*2; ++j) {
		       pos[j] = hex_to_char((rand_num >> (j*4))&0xf);
		}	       
	}

	return std::string(guid, guid+32);
}

} 
}

#endif
