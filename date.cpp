#include "date.h"

date::date()
{
	m_day = 1;
	m_month = 1;
	m_year = 1900;
}

date::date(int d, int m, int y)
{
	bool isValidDay = d >= 1 && d <= 31;
	bool isValidMonth = m >= 1 && m <= 12;
	bool isValidYear = y >= 1900 && y <= 2022;
	if (isValidDay && isValidMonth && isValidYear)
	{
		m_day = d;
		m_month = m;
		m_year = y;
	}
	else
	{
		std::cerr << "ERROR:Invalid Date" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void date::set_day(int day)
{
	m_day = day;
}

void date::set_month(int month)
{
	m_month = month;
}

void date::set_year(int year)
{
	m_year = year;
}

int date::get_day() const
{
	return m_day;
}

int date::get_month() const
{
	return m_month;
}

int date::get_year() const
{
	return m_year;
}
