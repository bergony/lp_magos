#include "../include/build.h"
#include <stdlib.h>
#include <ctime>

bool Build::done( void )
{
    if(m_set_done ==  (m_maze->get_numb_cell()-1) )
    {
        return true;
    }

    return false;
}

void Build::union_sets( int s1, int s2 )
{
    //Add on fisrt set
    for(std::set<int>::iterator it_s1 = m_sets_cell[s1].begin(); 
            it_s1 != m_sets_cell[s1].end(); it_s1++)
    {
        for(std::set<int>::iterator it_s2 = m_sets_cell[s2].begin(); 
                it_s2 != m_sets_cell[s2].end(); it_s2++)
        {
            if( !m_sets_cell[*it_s1].count(*it_s2) )
            {
                m_sets_cell[*it_s1].insert(*it_s2);
            }
        }
    }
    //ADd on second set.
    for(std::set<int>::iterator it_s2 = m_sets_cell[s2].begin(); 
            it_s2 != m_sets_cell[s2].end(); it_s2++)
    {
        for(std::set<int>::iterator it_s1 = m_sets_cell[s1].begin(); 
                it_s1 != m_sets_cell[s1].end(); it_s1++)
        {
            if( !m_sets_cell[*it_s2].count(*it_s1) )
            {
                m_sets_cell[*it_s2].insert(*it_s1);
            }
        }
    }
}
bool Build::is_on_set( int s1, int s2 )
{
    //Check the first SET
    for(std::set<int>::iterator it_s1 = m_sets_cell[s1].begin(); 
            it_s1 != m_sets_cell[s1].end(); it_s1++)
    {
        for(std::set<int>::iterator it_s2 = m_sets_cell[s2].begin(); 
                it_s2 != m_sets_cell[s2].end(); it_s2++)
        {
            if( m_sets_cell[*it_s1].count(*it_s2) )
            {
                return true;
            }
        }
    }
    //Check the Second Set
    for(std::set<int>::iterator it_s2 = m_sets_cell[s2].begin(); 
            it_s2 != m_sets_cell[s2].end(); it_s2++)
    {
        for(std::set<int>::iterator it_s1 = m_sets_cell[s1].begin(); 
                it_s1 != m_sets_cell[s1].end(); it_s1++)

        {
            if( m_sets_cell[*it_s2].count(*it_s1) )
            {
                return true;
            }
        }
    }

    return false;

}

bool Build::make( void )
{
    srand(time(NULL));  //!< Change send 
    int y{0};           //!< Coordinates Y
    int x{0};           //!< Coordinates X
    int i{0};           //!< Cell to be add.
    int look_cell{0};   //!< Cell set 
    int percent{0};     //!< Percent of the random Maze
    int number_of_percent{100};
    int rand_wall{0};   //!< valor to The wall to be random.

    percent = (m_maze->get_numb_cell() * number_of_percent) / 100;
    rand_wall = rand() % 3;

    if( m_set_done < percent)
    {
        y = rand() % (m_maze->get_rows());
        x = rand() % (m_maze->get_cols());
        i = m_maze->find_cell(x , y);
    }
    else
    {
        for(int cell_out{0} ; cell_out < m_maze->get_numb_cell(); cell_out++)
        {
            while(m_sets_cell[look_cell].size() > (unsigned int)(m_maze->get_numb_cell()-1) )
            {   
                look_cell++;
                x=0;
                y=0;
            }
            if( !is_on_set(cell_out, look_cell))
            {
                i = cell_out;
                break;
            }

            x++;

            if(x >= m_maze->get_cols())
            {
                x = 0;
                y++;
            }

            look_cell = 0;
        }
    }

    if( rand_wall == 0 && y != 0 && !is_on_set( i, i-m_maze->get_cols() ) )
    {
        union_sets(i, i-m_maze->get_cols());
        m_maze->set_cell_down(y , x, Maze::status_cell::top);
        m_maze->set_cell_down(y-1 , x, Maze::status_cell::down);
        m_set_done++;
        return true;
    }
    else if( rand_wall == 1 && x != 0 && !is_on_set(i , i-1  ))
    {
        union_sets(i, i-1);
        m_maze->set_cell_down(y , x, Maze::status_cell::left);
        m_maze->set_cell_down(y , x-1, Maze::status_cell::right);
        m_set_done++;
        return true;
    }
    else if( rand_wall == 2 && y != (m_maze->get_rows()-1) && !is_on_set( i, i+m_maze->get_cols()))
    {
        union_sets(i, i+m_maze->get_cols());
        m_maze->set_cell_down(y , x, Maze::status_cell::down);
        m_maze->set_cell_down(y+1 , x, Maze::status_cell::top);
        m_set_done++;
        return true;
    }
    else if(rand_wall == 3 && x != (m_maze->get_rows()-1) && !is_on_set( i, i+1 ) )
    {
        union_sets(i, i+1);
        m_maze->set_cell_down(y , x, Maze::status_cell::right);
        m_maze->set_cell_down(y , x+1, Maze::status_cell::left);
        m_set_done++;
        return true;
    }

    return false;
}

