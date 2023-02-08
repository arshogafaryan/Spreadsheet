#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>
#include <iostream>
#include "date.h"
#include "color.h"

class cell
{
	public:
		cell();
		cell(const std::string& value, const color& color);
		cell(const cell& value);
		cell& operator=(const cell& value);
		void set_value(const std::string& value);
		void set_color(const color& col);
		std::string get_value() const;
		color get_color() const;
		int toInt();
		double toDouble();
		date toDate();
		void reset();
	private:
		std::string m_value;
		color m_color;
		
		date stoD(std::string& str);
};

std::vector<std::string> split(const std::string str, const char c);
void swap_cells(cell& c1, cell& c2);

#endif
