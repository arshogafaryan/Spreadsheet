#include <iostream>
#include "cell.h"
#include "spreadsheet.h"
#include "date.h"
#include "color.h"

void test_cell_values()
{
    color col;
    cell c;
    col = color::Green;
    c.set_color(col);
    if (c.get_color() == color::Green)
        std::cout << "Color passed!" << std::endl;
        std::cout << "Date passed!" << std::endl;
    cell a;
    a.set_value("4.5");
    if (a.toDouble() == 4.5)
        std::cout << "Casting passed 1!" << std::endl;
    a.reset();
    a.set_value("4");
    if (a.toInt() == 4)
        std::cout << "Casting passed 2!" << std::endl;
    a.set_value("10.10.2010");
    if (a.toDate().get_day() == 10 && a.toDate().get_month() == 10 && a.toDate().get_year() == 2010)
        std::cout << "Casting passed 3!" << std::endl;
    
    spreadsheet table(3, 3);
    table.set_cell_at(0, 0, "Arsho");
    table.set_cell_at(0, 1, "4,5");
    table.set_cell_at(0, 2, "11.10.2004");
    table.set_cell_at(1, 0, "Artur");
    table.set_cell_at(1, 1, "12,25");
    table.set_cell_at(1, 2, "25.11.2013");
    table.set_cell_at(2, 0, "Aram");
    table.set_cell_at(2, 1, "20");
    table.set_cell_at(2, 2, "5.9.2010");
    if (table.get_cell_at(0, 0).get_value() == "Arsho" && table.get_cell_at(0, 2).get_value() == "17.12.2001")
        std::cout << "Spreadsheet passed!" << std::endl;
    table.print_table();
    table.swap_columns(0, 1);
    table.print_table();
    table.swap_rows(0, 2);
    table.print_table();
    table.remove_row(1);
    table.remove_column(0);
    table.print_table();
    table.add_column(0);
    table.add_row(0);
    table.p
    rint_table();
}
int main()
{
    test_cell_values();
}