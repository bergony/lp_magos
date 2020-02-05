
#include "../include/maze.h"

int Maze::get_cols( void ){ return m_cols; };

int Maze::get_rows( void ){ return m_rows; };

int Maze::get_numb_cell( void ){ return m_cols*m_rows; }

int Maze::get_maze_done( void ){ return m_maze_done; }

void Maze::set_maze_done( int x ){ m_maze_done = x; }

void Maze::set_cell_up( int x, int y, status_cell sc )
{
    m_cell_list[ find_cell(y,x) ] = m_cell_list[ find_cell(y,x) ] | (bit)sc;
}

void Maze::set_cell_up( int cell, status_cell sc )
{
    m_cell_list[ cell ] = m_cell_list[ cell ] | (bit)sc;

}

void Maze::set_cell_down( int x, int y, status_cell sc)
{
    m_cell_list[ find_cell(y,x)] = ~m_cell_list[ find_cell(y,x)] | (bit)sc;
    m_cell_list[ find_cell(y,x) ] = ~m_cell_list[ find_cell(y,x) ];
}

void Maze::set_cell_down( int cell, status_cell sc)
{
    m_cell_list[ cell] = ~m_cell_list [cell ] | (bit)sc;
    m_cell_list[ cell ] = ~m_cell_list[ cell ];
}

bit Maze::get_cell( int x, int y )
{
    return m_cell_list[  find_cell(y,x)  ];
}

bool Maze::is_cell_up( int x, int y, status_cell sc )
{
    if((bit)sc == (m_cell_list[ find_cell(y,x) ] & (bit)sc) ) return true;

    return false;
}

bool Maze::is_cell_up(int cell, status_cell sc)
{
    if((bit)sc == (m_cell_list[ cell ] & (bit)sc) ) return true;

    return false;
}

bool Maze::is_way_up( int cell)
{
    if( is_cell_up( cell, Maze::status_cell::discarded ))
    {
        return true;
    }

    if( is_cell_up( cell, Maze::status_cell::way ) )
    {
        return true;
    }

    return false;
}
