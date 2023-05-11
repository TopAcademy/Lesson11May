#include <iostream>
#include "Student.h"

int main() {
    Student s1("Joe Biden", 2001);
    std::cout << s1.get_info() << std::endl;
    s1.add_grade(3);
    s1.add_grade(2);
    s1.show_rating_log();

    Student s2 = s1;
    s2.set_info("Joe Biden 2", 2002);
    s2.add_grade(5);
    s2.add_grade(5);
    std::cout << s2.get_info() << std::endl;
    s2.show_rating_log();
    s1.show_rating_log();
}