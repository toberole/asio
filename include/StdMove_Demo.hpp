//
// Created by linuxer on 1/31/19.
//

#ifndef ASIO_STDMOVE_DEMO_H
#define ASIO_STDMOVE_DEMO_H

#include <string>
#include <iostream>

class Student {
public:
    int age;
    std::string name;

public:
    Student() {
        std::cout << "Student() constructor" << std::endl;
    }

    Student(int _age, std::string _name) :
            age(age),
            name(_name) {

        std::cout << "Student(int _age, std::string _name) constructor" << std::endl;
    }

    // copy constructor
    Student(Student &stu) {
        this->age = stu.age;
        this->name = stu.name;

        std::cout << "copy constructor" << std::endl;
    }

    // std::move copy constructor
    Student(Student &&stu) {
        this->age = stu.age;
        this->name = std::move(stu.name);

        std::cout << "std::move copy constructor" << std::endl;
    }
};

#endif //ASIO_STDMOVE_DEMO_H
