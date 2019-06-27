#ifndef DT_BASE_INSTANCE_COUNTER_HPP
#define DT_BASE_INSTANCE_COUNTER_HPP

#include "uuid.hpp"
#include "rc_string.hpp"

namespace dt {
namespace base {

struct DefaultInstanceCounter {
    static dt::base::String InstanceName()  {
        return "DefaultInstanceCounter";
    }
};

template <class T = DefaultInstanceCounter>
class InstanceCounter {
public:
    InstanceCounter(const dt::base::String& uuid, const dt::base::String& name) : uuid_(uuid), name_(name) {
        static std::uint64_t id = 0;
        id_ = ++id;
    }

    InstanceCounter(const dt::base::String& name) : InstanceCounter(dt::util::GenerateUUID(), name) {
    }

    InstanceCounter() : InstanceCounter(T::InstanceName()) {
        name_ += dt::base::String(id_);
    }

    String UUID() const {
        return uuid_;
    }

    String Name() const {
        return name_;
    }

    void SetName(const std::string& name) {
        name_ = name;
    }

    std::uint64_t ID() const {
        return id_;
    }

    template <class U>
    bool operator == (const InstanceCounter<U> other) const{
        return InstanceName() == other.InstanceName() && id_ == other.id_;
    }

public:
    static dt::base::String InstanceName()  {
        return typeid(T).name();
    }

private:
    dt::base::String     uuid_;
    dt::base::String     name_;
    std::uint64_t        id_     = 0;
};

}
}

#endif