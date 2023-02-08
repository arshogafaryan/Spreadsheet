#ifndef DATE_H
#define DATE_H

#include <iostream>

class date
{
	public:
		date();
		date(int d, int m, int y);
		int get_day() const;
		int get_month() const;
		int get_year() const;
		void set_day(int day);
		void set_month(int month);
		void set_year(int year);
	private:
		int m_day;
		int m_month;
		int m_year;
};

#endif
