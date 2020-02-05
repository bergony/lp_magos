#ifndef _SOLVE_H_
#define _SOLVE_H_

#include <stack>

typedef unsigned char bit;

#include "../include/maze.h"

/// <b>Class</b> Solve <i>Class that recive a Maze to be Solve.</i>
class Solve
{
    private:

        Maze *m_maze;                       //!< Reference to Maze.
        std::stack< int > m_stack_cell;     //!< Stack Cell to be save.
        std::stack< int > m_stack_ways;     //!< Stack Way to be save. 
        int m_cell_player{0};               //!< Cell of point check.
        int m_numb_way{0};                 //!< Numbers of posible way.
        
        //Solver Left hand var.
        int front{1};       //< var to save what is the front on cell.
        int hand{4};        //< var to save what is the left hand on cell
        int Turners{0};     //< Numeber of turn the cell make.

    public:

        //==================Special members========================
        /// ! Constructor Solve
        /*!
        \param Maze *m Reference to a maze. 
        */
        Solve( Maze *m): m_maze{m} 
        {
            /* EMPTY */
        }

        /// ! Constructor Solve Default
        Solve(){}
        
        /// ! Destructors Solve
        ~Solve( void ){ }
        
        /// ! Copy Solve
        Solve( const Solve & clone )
        {   
            m_maze = clone.m_maze;
            m_stack_cell = clone.m_stack_cell;
            m_stack_ways = clone.m_stack_ways;
            m_cell_player = clone.m_cell_player;
            m_numb_way = clone.m_numb_way;
        }

        /// ! Assignment operator.
        Solve& operator=( const Solve & s)
        {
            this->m_maze = s.m_maze;
            this->m_stack_cell = s.m_stack_cell;
            this->m_stack_ways = s.m_stack_ways;
            this->m_cell_player = s.m_cell_player;
            this->m_numb_way = s.m_numb_way;

            return *this;
        }

        /// ! Method to check if the maze is Done
        /*!
        \return True if the Cell Player are the last one. 
        */
        bool is_done( void );

        /// ! Method to get with way de player_cell goes save on way stack
        void get_way( void );

        /// ! Method to get numbers of posible ways
        /*!
        \return int numbers of ways. 
        */
        int get_way_numb( void );

        /// ! Move to the next Cell backtrack.
        void move( void );

        /// ! Move to the next cell left hand.
        bool move_left( void );

};

#endif
