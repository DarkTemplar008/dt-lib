#include "../mem_fun.hpp"
#include <iostream>
#include <vector>

struct EventListener {
    void OnEvent0Changed() {
        std::cout << id_  << ":" <<  __FUNCTION__ << std::endl;
    }
    void OnEvent1Changed(int i) {
        std::cout << id_  << ":" <<  __FUNCTION__  << ":" << i << std::endl;
    }
    void OnEvent2Changed(int i, int j) {
        std::cout << id_  << ":" <<  __FUNCTION__  << ":" << i << "," << j << std::endl;
    }
    void OnEvent3Changed(int i, int j, int k) {
        std::cout << id_  << ":" <<  __FUNCTION__  << ":" << i << "," << j << "," << k << std::endl;
    }

    EventListener() {
        static int id = 0;
        id_ = ++id;
    }
    int id_ = 0;
};

int main(int argc, char* argv[]) {
    std::vector<EventListener> event_listener_vec;
    EventListener el0;
    event_listener_vec.emplace_back(el0);
    EventListener el1;
    event_listener_vec.emplace_back(el1);
    EventListener el2;
    event_listener_vec.emplace_back(el2);

    for (auto& el : event_listener_vec) {
        auto mem_fun = dt::util::MakeMemFun<void>(&EventListener::OnEvent0Changed);
        mem_fun(&el);
    }

    int i = 0;
    for (auto& el : event_listener_vec) {
        auto mem_fun = dt::util::MakeMemFun<void>(&EventListener::OnEvent1Changed);
        mem_fun(&el, ++i);
    }

    int j = 0;
    for (auto& el : event_listener_vec) {
        auto mem_fun = dt::util::MakeMemFun<void>(&EventListener::OnEvent2Changed);
        mem_fun(&el, ++i, ++j);
    }

    int k = 0;
    for (auto& el : event_listener_vec) {
        auto mem_fun = dt::util::MakeMemFun<void>(&EventListener::OnEvent3Changed);
        mem_fun(&el, ++i, ++j, ++k);
    }

    return 0;
}