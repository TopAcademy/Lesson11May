// Date.h
#pragma once
#include <iostream>
#include <string>
using UShort = unsigned short;
using UInt = unsigned int;

class Date
{
private:
    UShort day;
    UShort month;
    UShort year;
    std::string timezone;
    static std::string month_names[13];
    static short month_days[13];
public:
    // constructors
    Date();
    Date(UShort d, UShort m, UShort y);
    // other methods
    void print_short();       // prints date in the format: "D.MM.YYYY";
    void print_long();        // prints date in the format: "D of MonthName, YYYY";
    void add_days(UInt d);    // adds <d> days to stored date
};

std::string Date::month_names[13]{
    "", "Jan", "Feb", "March",
        "Apr", "May", "June", "July",
        "Aug", "Sept", "Okt", "Nov", "Dec"
};

short Date::month_days[13]{
    0, 31,28,31,30,31,30,31,31,30,31,30,31
};

/*
 * Constructors
 */

 // Default constructor
Date::Date()
{
    day = 1;
    month = 1;
    year = 1970;
    timezone = "GMT+3 (Moscow)";
}

// Constructor with 3 params
Date::Date(UShort d, UShort m, UShort y) : Date()
{
    // check month
    if ((m < 1) || (m > 12)) return;
    // check day of month

    day = d;
    month = m;
    year = y;
}

// Print date in short format (D.MM.YYYY)
void Date::print_short()
{
    std::cout << this->day << '.';
    if (this->month < 10) std::cout << '0';
    std::cout << this->month << '.';
    std::cout << this->year << std::endl;
}

// Print date in long format (D of monthname YYYY)
void Date::print_long()
{
    std::cout << this->day << " of ";
    std::cout << month_names[month];
    std::cout << ", " << this->year << std::endl;
}

// Adds <d> days to date (d<=365)
void Date::add_days(UInt d)
{
    if (d > 365) return;
    // Доп. домашнее задание
}
