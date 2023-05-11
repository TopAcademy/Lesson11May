#pragma once
#include <iostream>
#include <string>

/*
 Class "Student"
 Represents student person with params:
 full name, year of entry, array of grades
*/
class Student 
{
private:
    // state variables
    std::string full_name;
    unsigned short entry_year;
    unsigned short * grades;
    // common (static) values
    static std::string school_name;
    static unsigned short grades_max_size;
public:
    // constructors & desutructor
    Student();
    Student(std::string n, unsigned short y);
    Student(const Student& obj2);
    ~Student();
    // setter methods
    void set_info(std::string n, unsigned short y);
    void add_grade(unsigned short g);
    // getter methods
    const std::string get_info();
    const void show_rating_log();
};

/*
 * Static inits
 */

std::string Student::school_name = "Top Academy";
unsigned short Student::grades_max_size = 10;

/*
 * Constructors & destructor
 */

// Default constructor
Student::Student()
{
    full_name = "Noname";
    entry_year = 0;
    grades = new unsigned short [grades_max_size];
    for (int i=0; i<grades_max_size; i++)
        grades[i] = 0;
}

// Constructor with init params
Student::Student(std::string n, unsigned short y) : Student()
{
    this->set_info(n, y);
}

// Copy constructor
Student::Student(const Student& obj2)
{
    this->full_name = obj2.full_name;
    this->entry_year = obj2.entry_year;
    this->grades = new unsigned short [grades_max_size];
    for (int i=0; i<grades_max_size; i++)
        this->grades[i] = obj2.grades[i];
}

// Destructor
Student::~Student()
{
    if (grades != nullptr)
        delete[] grades;
}

/*
 * Setter methods
 */

// Set base info: full name and enrty year
void Student::set_info(std::string n, unsigned short y)
{
    if (n.length() > 1)
        full_name = n;
    else
        full_name = "Noname";
    if ((y > 2000) && (y < 2023)) 
        entry_year = y;
    else
        entry_year = 0;
}

// Add new grade to grades array
void Student::add_grade(unsigned short g)
{
    for (int i=0; i<grades_max_size; i++) {
        if (grades[i] == 0) {
            grades[i] = g;
            break;
        }
    }
}

/*
 * Getter methods
 */

// get base info of the student
const std::string Student::get_info()
{
    std::string s = "Name: #, Year: $";
    s.replace(15, 1, std::to_string(entry_year));
    s.replace(6, 1, full_name);
    return s;
}

// show rating log
const void Student::show_rating_log()
{
    std::cout << "Rating log of " << full_name << ":\n";
    for (int i=0; i<grades_max_size; i++) {
        if (grades[i]) 
            std::cout << grades[i] << "; ";
    }
    std::cout << std::endl;
}