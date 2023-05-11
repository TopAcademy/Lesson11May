#include <iostream>
#include "Student.h"

int main() {
    Student s1("Joe Biden", 2001);
    std::cout << s1.get_info() << std::endl;
    s1.add_grade(3);
    s1.add_grade(2);
    s1.show_rating_log();
}