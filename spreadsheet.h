#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "cell.h"
#include <iostream>
#include <string>

class spreadsheet
{
	public:
		spreadsheet(size_t rows, size_t columns);
		~spreadsheet();
		void set_cell_at(size_t row, size_t column, const std::string& value);
		void set_cell_at(size_t row, size_t column, const cell& value);
		cell get_cell_at(size_t row, size_t column) const;
		void add_row(size_t num);
		void add_column(size_t num);
		void remove_row(size_t num);
		void remove_column(size_t num);
		void swap_rows(int row1, int row2);
		void swap_columns(int column1, int column2);

		void print_table();
	private:
		size_t m_rows;
		size_t m_columns;
		cell** m_cells;
};

#endif
