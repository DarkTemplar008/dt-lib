#include "../uuid.hpp"

#include <set>
#include <iostream>

int main(int argc, char* argv[]) {
	std::set<std::string> guid_set;
	for (;;) {
		std::string guid = dt::util::GenerateUUID();
		std::cout << guid << std::endl;
		if ( guid_set.find(guid) != guid_set.end()) {
			break;
		}
		guid_set.insert(guid);
	}
	return 0;
}