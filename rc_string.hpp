#ifndef DT_BASE_RC_STRING_HPP
#define DT_BASE_RC_STRING_HPP

#include <memory>
#include <string>

namespace dt {
namespace base {

class String {
public:
	String() {
		static std::shared_ptr<std::string> empty = std::make_shared<std::string>();
		impl_ = empty;
	}

	template <class T>
	String(T obj) {
		impl_ = std::make_shared<std::string>(std::to_string(obj));
	}

	String(const char* str) {
		impl_ = std::make_shared<std::string>(str);
	}

	String(const std::string& str) {
		impl_ = std::make_shared<std::string>(str);
	}

	String(const String& other) {
		impl_ = other.impl_;
	}

	String(String&& other) {
		impl_ = other.impl_;
		other.impl_.reset();
	}

	String& operator=(const String& other) {
		impl_ = other.impl_;
		return *this;
	}

	String& operator=(String&& other) {
		impl_ = other.impl_;
		other.impl_.reset();
        	return *this;
	}

	String& operator=(const std::string& str) {
		impl_ = std::make_shared<std::string>(str);
		return *this;
	}

	operator std::string() const {
		return *impl_;
	}

	bool operator == (const String& other) {
		if (impl_ == other.impl_) {
			return true;
		} else if (*impl_ == *other.impl_) {
			impl_ = other.impl_;
			return true;
		}
		return false;
	}

	bool operator == (const String& other) const {
		if (impl_ == other.impl_ || *impl_ == *other.impl_) {
			return true;
		}
		return false;
	}
	
	bool operator != (const String& other) const {
		if (impl_ == other.impl_) {
			return false;
		}
		return !operator == (other);
	}

	bool operator == (const char* str) const {
		return *impl_ == str;
	}
	
	bool operator != (const char* str) const {
		return !operator == （str）;
	}
	
	bool operator == (const std::string& str) const {
		return *impl_ == str;
	}
	
	bool operator != (const std::string& str) const {
		return ! operator == (str);
	}
	
	bool operator < (const String& other) const {
		return *impl_ < *other.impl_;
	}

private:
	std::shared_ptr<std::string> impl_;
};

String operator + (const String& first, const String& second) {
    std::string result(first);
    result += static_cast<std::string>(second);
    return result;
}

String& operator += (String& first, const String& second) {
    first = first + second;
    return first;
}

template <class OStream>
OStream& operator << (OStream& os, const String& str) {
    os << static_cast<std::string>(str);
    return os;
}

}
}

#endif
