#include "cell.h"

cell::cell():m_value{}, m_color(color::White)
{}

cell::cell(const std::string& value, const color& color)
{
	m_value = value;
	m_color = color;
}

cell::cell(const cell& value)
{
	this->m_value = value.get_value();
	this->m_color = value.get_color();
}

cell& cell::operator=(const cell& value)
{
	this->m_value = value.get_value();
	this->m_color = value.get_color();
	return *this;
}

void cell::set_value(const std::string& value)
{
	m_value = value;
}

void cell::set_color(const color& col)
{
	m_color = col;
}

std::string cell::get_value() const
{
	return m_value;
}

color cell::get_color() const
{
	return m_color;
}

int cell::toInt()
{
	return std::stoi(m_value);
}

double cell::toDouble()
{
	return std::stod(m_value);
}

date cell::toDate()
{
	return stoD(m_value);
}

void cell::reset()
{
	m_value = "";
}

date cell::stoD(std::string& str)
{
	date new_date;
	std::vector<std::string> tab(split(str, '.'));
	int date = std::stoi(tab[0]);
	int month = std::stoi(tab[1]);
	int year = std::stoi(tab[2]);
	new_date.set_day(date);
	new_date.set_month(month);
	new_date.set_year(year);
	return new_date;
}

std::vector<std::string> split(const std::string str, const char c)
{   
	std::vector<std::string> tab;
    size_t i = 0;    
    std::string s; 
    while (str[i] != '\0') 
    {
        if (str[i] != c) 
        {
            s += str[i]; 
        }
        else
        {
            tab.push_back(s);
            s.clear();
        }
        i++;
    }
	tab.push_back(s);
	return (tab);
}

void swap_cells(cell& c1, cell& c2)
{
	cell tmp;
	tmp = c1;
	c1 = c2;
	c2 = tmp;
}
