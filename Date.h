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
public:
    // constructors
    Date();
    Date(UShort d, UShort m, UShort y);
    // other methods
    void print_short();       // prints date in the format: "DD.MM.YYYY";
    void print_long();        // prints date in the format: "DD of MonthName, YYYY";
    void add_days(UInt d);    // adds <d> days to stored date
};

/*
 * Constructors
 */

// Default constructor
Date::Date()
{
    day = 1;
    month = 2;
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