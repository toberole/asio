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

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};

class Derive : public Base {
public:
    virtual void f() {
        std::cout << "Derive::f()" << std::endl;
    }
};


typedef void(*Func)(void);

void test_th(int i) {
    std::cout << "i = " << i << std::endl;

    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


int main() {
    std::cout << "Hello, World!" << std::endl;


//    service.post(run_dispatch_and_post);
//
//    service.run();

//    Base* b = new Derive();
//    b->f();

//    for (int i = 0; i < 10000; ++i) {
//        std::thread *th = new std::thread(test_th,i);
//        (*th).detach();
//    }


    std::cout << "press any key to exit ......" << std::endl;
    getchar();
    return 0;
}