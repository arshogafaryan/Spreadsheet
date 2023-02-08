#include "spreadsheet.h"

spreadsheet::spreadsheet(size_t rows, size_t columns)
{
	m_cells = new cell*[rows];
	for (unsigned int i = 0; i < rows; ++i)
	{
		m_cells[i] = new cell[columns];
	}
	m_rows = rows;
	m_columns = columns;
}

spreadsheet::~spreadsheet()
{
	delete[] m_cells;
}

void spreadsheet::set_cell_at(size_t row, size_t column, const std::string& value)
{
	m_cells[row][column].set_value(value);
}

void spreadsheet::set_cell_at(size_t row, size_t column, const cell& value)
{
	if (row > m_rows || column > m_columns)
	{
		std::cerr << "Range Error!" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_cells[row][column] = value;
}

cell spreadsheet::get_cell_at(size_t row, size_t column) const
{
	if (row > m_rows || column > m_columns)
	{
		std::cerr << "Range Error!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return m_cells[row][column];
}

void spreadsheet::add_row(size_t num)
{
	++m_rows;
	cell** tmp = new cell*[m_rows];
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		tmp[i] = new cell[m_columns];
	}
	for (unsigned int i = 0; i < m_rows - 1; ++i)
	{
		for (unsigned int j = 0; j < m_columns; ++j)
		{
			if (i < num)
				tmp[i][j] = m_cells[i][j];
			else
				tmp[i + 1][j] = m_cells[i][j];
		}
	}
	delete[] m_cells;
	m_cells = tmp;
	tmp = nullptr;
}

void spreadsheet::add_column(size_t num)
{
	++m_columns;
	cell** tmp = new cell*[m_rows];
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		tmp[i] = new cell[m_columns];
	}

	for (unsigned int i = 0; i < m_rows; ++i)
	{
		for (unsigned int j = 0; j < m_columns; ++j)
		{
			if (j < num)
			{
				tmp[i][j] = m_cells[i][j];
			}
			else
				tmp[i][j + 1] = m_cells[i][j];
		}
	}
	delete[] m_cells;
	m_cells = tmp;
	tmp = nullptr;
}

void spreadsheet::remove_row(size_t num)
{
	--m_rows;
	if (m_rows == 0)
	{
		std::cerr << "Spreadsheet deleted" << std::endl;
		exit(1);
	}
	cell** tmp = new cell*[m_rows];
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		tmp[i] = new cell[m_columns];
	}
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		for (unsigned int j = 0; j < m_columns; ++j)
		{
			if (i < num)
				tmp[i][j] = m_cells[i][j];
			else
				tmp[i][j] = m_cells[i + 1][j];
		}
	}
	delete[] m_cells;
	m_cells = tmp;
	tmp = nullptr;
}

void spreadsheet::remove_column(size_t num)
{
	--m_columns;
	if (m_columns == 0)
	{
		std::cerr << "Spreadsheet deleted" << std::endl;
		exit(1);
	}
	cell** tmp = new cell*[m_rows];
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		tmp[i] = new cell[m_columns];
	}
	for (unsigned int i = 0; i < m_rows; ++i)
	{
		for (unsigned int j = 0; j < m_columns; ++j)
		{
			if (j < num)
				tmp[i][j] = m_cells[i][j];
			else
				tmp[i][j] = m_cells[i][j + 1];
		}
	}
	delete[] m_cells;
	m_cells = tmp;
	tmp = nullptr;
}

void spreadsheet::swap_rows(int row1, int row2)
{
	for (int i = 0; i < m_columns; ++i)
	{
		swap_cells(m_cells[row1][i], m_cells[row2][i]);
	}
}

void spreadsheet::swap_columns(int column1, int column2)
{
	for (int i = 0; i < m_rows; ++i)
	{
		swap_cells(m_cells[i][column1], m_cells[i][column2]);
	}
}

void spreadsheet::print_table()
{
	for (int i = 0; i < m_rows; ++i)
	{
		for (int j = 0; j < m_columns; ++j)
		{
			std::cout << m_cells[i][j].get_value() << " "; 
		}
		std::cout << '\n';
	}
}