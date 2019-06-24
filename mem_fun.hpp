#ifndef MEM_FUN_HPP
#define MEM_FUN_HPP

namespace dt {
namespace util {

template <class Fun, class R>
struct MemFun {
	MemFun(Fun fun) : fun_(fun) {}
	template <class T, class... A>
	R operator () (T* obj, A... arg) {
		return (obj->*fun_)(arg...);
	}
	Fun fun_;
};

template <class R, class Fun>
MemFun<Fun, R> MakeMemFun(Fun fun) {
	return MemFun<Fun, R>(fun);
}

}
}

#endif
