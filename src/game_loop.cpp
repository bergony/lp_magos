#include "../include/game_loop.h"
#include <iomanip>

void Game_Loop::initializer( void )
{
    // Set back_track to true use back solve.
    // set back_track to false use hand solve.
    back_track = false;
    if( rows * 8 > width || cols * 8 > height )
    {
        std::cout << "The Canvas Size is to short to Draw\n";
        break_loop = true;
    }
    if(rows < 2 || cols < 2)
    {
        std::cout << "The Rows our Coluns is under the range";
        break_loop = true;
    }

    if(width < 100 || height < 100)
    {

        std::cout << "The width or he height is under the range";
        break_loop = true;
    }
    if(rows == 2 && cols == 2 )
    {

        std::cout << "The Rows and coluns are under the range";
        break_loop = true;
    }
    m.set_cell_up(0,0, Maze::status_cell::entrace);
    for( int i{0}; i < rows; i++)
    {
        for(int j{0}; j < cols; j++)
        {
            m.set_cell_up( i,j, Maze::status_cell::top );
            m.set_cell_up( i,j, Maze::status_cell::down );
            m.set_cell_up( i,j, Maze::status_cell::left );
            m.set_cell_up( i,j, Maze::status_cell::right );
        }
    }
    m.set_cell_up(rows-1,cols-1, Maze::status_cell::exit);

    render();
    n_pictures++;
    percent = 100.0/(cols*rows);
    std::cout << "\nBUILDING THE MAZE \n";
    std::cout << std::setprecision(4) << percent << "%\n";
}

void Game_Loop::update( void )
{
    if(break_loop == false)
    {
        if( !b.done() && b.make() )
        {
            render();

            percent += 100.0/(cols*rows);
            std::cout << std::setprecision(4) << percent << "%\n";
            n_pictures++;
        }

        if( b.done())
        {
            if(percent <= 99 && percent > 0)
            {
                std::cout << "100%\n";
            }
            if(percent > 0)
            {
                std::cout << "\nSOLVING THE MAZE \n";
                percent = -1;
                printer = true;
            }
        }

        if( b.done() && !s.is_done())
        {
            if(back_track == true)
            {
                s.move();
                std::cout << "Solving Back " << trys << "Moves\n";
                s_string = s_back_string;
                render();
                trys++;
            }else{
                if(s.move_left())
                {
                    std::cout << "Solving Hand " << trys << "Moves\n";
                    s_string = s_hand_string;
                    render();
                    trys++;
                }
            }
        }
    }
}
void Game_Loop::render( void )
{

    Render rdr( &m, width , height);
    if( (!b.done() || percent != 100) && printer == false  )
    {   
            output = b_string + std::to_string(n_pictures);
            rdr.draw(output);
    }

    if( b.done() && !s.is_done())
    {
        output = s_string + std::to_string(trys);
        rdr.draw(output);
    }
    if( b.done() && s.is_done())
    {
        output = s_string + std::to_string(trys);
        rdr.draw(output);
    }
}

bool Game_Loop::done( void )
{

    if( b.done() && s.is_done() )
    {
        return true;
    }

    if(break_loop == true)
    {
        std::cout << "wrong argument numbers\n";
        std::cout << "One of argument are lower then configuration\n";
        std::cout << "lower configuration (2x3) or (3x2) and (100x100)\n";
        return true;
    }

    return false;

}
