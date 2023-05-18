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
    UShort date_to_days();
    void days_to_date(UShort d);
    // static
    static const UShort start_year;
    // constructors
    Date();
    Date(UShort d, UShort m, UShort y);
    // other methods
    void print_short();       // prints date in the format: "D.MM.YYYY";
    void print_long();        // prints date in the format: "D of MonthName, YYYY";
    void add_days(UInt d);    // adds <d> days to stored date
};

const UShort Date::start_year = 1970;

std::string Date::month_names[13] {
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

// ����������� ���� ������� � ����� ����,
// ��������� � 1.01.1970 �. � ���������� ��� �����
UShort Date::date_to_days()
{
    UShort result = 0;
    UShort years_count = this->year - Date::start_year;
    // ���� � ��������� �����
    result += (years_count * 365);
    // ������� ���������� ����
    result += (years_count / 4);
    // ���� � ��������� ������ �������
    UShort months_count = this->month - 1;
    for (int i = 0; i < months_count; i++) {
        result += month_days[i+1];
    }
    // ���� ������� ��� ���������� - �� ��� +1
    if (this->year % 4 == 0) result += 1;
    // ��������� ���
    result += this->day - 1;
    return result;
}


// ����������� ����� ���� � 1.01.1970
// � ������ ���� (��� Date)
void Date::days_to_date(UShort d)
{
    // ������� ���
    UShort years = d / 365;
    years -= years / (365 / 4);
    // ������� �������
    d = d % ((years*365) + (years / (365 / 4)));
    UShort months = 0, temp = 0;
    int i;
    for (i = 1; i <= 12; i++) {
        temp += month_days[i];
        if (temp <= d) months++;
        else break;
    }
    // ����� �����
    temp -= month_days[i];
    if ((years + start_year) % 4 == 0) temp += 1;
    d = d % temp;
    //Date result = Date(years + start_year, months, d);
    this->year = years + Date::start_year;
    this->month = months + 1;
    this->day = d + 1;
}


// Adds <d> days to date (d<=365)
void Date::add_days(UInt d)
{
    UShort date_in_days = date_to_days();
    date_in_days += d;
    this->days_to_date(date_in_days);
}
