
#include "../include/solve.h"

bool Solve::is_done( void )
{
    if( m_cell_player == m_maze->get_numb_cell()-1 )
    {

        m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
        return true;
    }
    return false;
}

void Solve::get_way( void )
{
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::top) &&
            !m_maze->is_way_up( m_cell_player -  m_maze->get_cols() ))
    {
        m_stack_ways.push(1);
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::left) &&
            !m_maze->is_way_up( m_cell_player-1 ))
    {
        m_stack_ways.push(2);
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::down) &&
            !m_maze->is_way_up( m_cell_player+m_maze->get_cols() ))
    {
        m_stack_ways.push(3);
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::right) &&
            !m_maze->is_way_up( m_cell_player+1))
    {
        m_stack_ways.push(4);
    }
}
int Solve::get_way_numb( void )
{
    m_numb_way = 0;
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::top) &&
            !m_maze->is_way_up(m_cell_player - m_maze->get_cols()))
    {
        m_numb_way++;
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::left) &&
            !m_maze->is_way_up( m_cell_player - 1))
    {
        m_numb_way++;
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::down) &&
            !m_maze->is_way_up( m_cell_player + m_maze->get_cols()))
    {
        m_numb_way++;
    }
    if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::right) &&
            !m_maze->is_way_up( m_cell_player + 1))
    {
        m_numb_way++;
    }
    return m_numb_way;
}

void Solve::move( void )
{
    if(get_way_numb() > 0 )
    {
        get_way();
        m_stack_cell.push(m_cell_player);
        m_maze->set_cell_up( m_stack_cell.top() , Maze::status_cell::way );

        if(m_stack_ways.top() == 1)
        {
            m_cell_player -= m_maze->get_cols();
            m_stack_ways.pop();

        }
        else if(m_stack_ways.top() == 2)
        {
            m_cell_player -= 1;
            m_stack_ways.pop();
        }
        else if(m_stack_ways.top() == 3)
        {
            m_cell_player += m_maze->get_cols();
            m_stack_ways.pop();

        }
        else if(m_stack_ways.top() == 4)
        {
            m_cell_player += 1;
            m_stack_ways.pop();
        }
    }
    else
    {

        m_maze->set_cell_up( m_cell_player, Maze::status_cell::discarded );
        if( m_maze->is_cell_up( m_cell_player, Maze::status_cell::way))
        {
            m_maze->set_cell_down(m_cell_player, Maze::status_cell::way);
        }
        m_cell_player = m_stack_cell.top();
        m_stack_cell.pop();
        while( m_stack_ways.empty() )
        {
            m_stack_ways.pop();
        }
    }

}

bool Solve::move_left( void )
{
    switch (front)
    {
        case 1:
            if( m_maze->is_cell_up( m_cell_player, Maze::status_cell::left ) &&
                    !m_maze->is_cell_up( m_cell_player, Maze::status_cell::top) &&
                    !m_maze->is_way_up( m_cell_player - m_maze->get_cols() ))
            {
                Turners = 0;
                m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                m_cell_player -= m_maze->get_cols();
                return true;
            }
            else
            {
                if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::left )) 
                {
                    Turners = 0;
                    front = 4;
                    hand = 3;
                    m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                    m_cell_player -= 1;
                    return true;
                }
                else
                {
                    Turners++;
                    front = 2;
                    hand = 1;
                }
                break;
            }

        case 2:
            if( m_maze->is_cell_up( m_cell_player, Maze::status_cell::top ) &&
                    !m_maze->is_cell_up( m_cell_player, Maze::status_cell::right) && 
                    !m_maze->is_way_up( m_cell_player+1 ))
            {
                Turners = 0;
                m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                m_cell_player += 1;
                return true;
            }
            else
            {
                if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::top ))
                {
                    Turners = 0;
                    front = 1;
                    hand = 4;
                    m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                    m_cell_player -= m_maze->get_cols();
                    return true;
                }
                else
                {
                    Turners++;
                    front = 3;
                    hand = 2;
                }
                break;
            }
        case 3:
            if(     m_maze->is_cell_up( m_cell_player, Maze::status_cell::right ) &&
                    !m_maze->is_cell_up( m_cell_player, Maze::status_cell::down) &&
                    !m_maze->is_way_up( m_cell_player+m_maze->get_cols() ))
            {
                Turners = 0;
                m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                m_cell_player += m_maze->get_cols();
                return true;
            }
            else
            {

                if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::right ))
                {
                    Turners = 0;
                    front = 2;
                    hand = 1;
                    m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                    m_cell_player += 1;
                    return true;
                }
                else
                {
                    Turners++;
                    front = 4;
                    hand = 3;
                }
                break;
            }

        case 4:
            /// if Left hand have wall and front wall is not up and cell in front is not way and not discarted.
            if(     m_maze->is_cell_up( m_cell_player, Maze::status_cell::down ) &&
                    !m_maze->is_cell_up( m_cell_player, Maze::status_cell::left) &&
                    !m_maze->is_way_up( m_cell_player-1))
            {
                Turners = 0;
                m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                m_cell_player -= 1;
                return true;
            }else
            {
                // if not have wall on left.
                if( !m_maze->is_cell_up( m_cell_player, Maze::status_cell::down))
                {
                    Turners = 0;
                    front = 3;
                    hand = 2;
                    m_maze->set_cell_up( m_cell_player , Maze::status_cell::way );
                    m_cell_player += m_maze->get_cols();
                    return true;
                }
                else
                {
                    Turners++;
                    front = 1;
                    hand = 4;
                }
                break;
            }
    }

    return false;
}


