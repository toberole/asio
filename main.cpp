#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

boost::asio::io_service service;

void func(int i) {
    std::cout << "func called, i= " << i << std::endl;
}

void run_dispatch_and_post() {
    for (int i = 0; i < 10; i += 2) {
        service.dispatch(boost::bind(func, i));
        service.post(boost::bind(func, i + 1));
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    service.post(run_dispatch_and_post);

    service.run();


    std::cout << "press any key to exit ......" << std::endl;
    getchar();
    return 0;
}