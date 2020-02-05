#ifndef _MAZE_H_
#define _MAZE_H_

#include <iostream>
#include <vector>
#include <bitset>

typedef unsigned char bit; //!< to use as a bit.

/// <b>Class</b> Maze <i>Class create a Maze to be Build, Solve and Render.</i>
class Maze
{
    private:
       
        bit m_cell;                     //!< Cell of Maze
        std::vector< bit >m_cell_list;  //!< List of a Cell of maze.
        int m_cols;                     //!< Numbers Of colums.
        int m_rows;                     //!< Numbers of Rows.
        int m_maze_done{0};

    public:
        

        /// <b> enum class</b> Status <i> Type of status cell and them value.</i>
        enum class status_cell
        {
            top = (bit)1,
            down = (bit)2,
            left = (bit)4,
            right= (bit)8,
            way = (bit)16,
            discarded = (bit)32,
            entrace = (bit)64,
            exit = (bit)128
        };

        //==================Special members========================
        /// ! Constructor Maze
        /*!
        \param int c Numbers of colums. 
        \param int r Numbers of Rows.
        */
        Maze( int c = 0 , int r = 0 ) :
            m_cols{c}, m_rows{r}
        {
            for(int i{0}; i < r*c; i++)
            {
                m_cell = (bit)0;
                m_cell_list.push_back( m_cell );
            }
        }

        /// ! Destructors Maze.
        ~Maze(){}

        Maze( const Maze & clone)
        {
            m_cell = clone.m_cell;
            m_cell_list = clone.m_cell_list;
            m_cols = clone.m_cols;
            m_rows = clone.m_rows;
        }

        /// ! Assignmentt Operator.
        Maze& operator=( const Maze & m )
        {
            this->m_cell = m.m_cell;
            this->m_cell_list = m.m_cell_list;
            this->m_cols = m.m_cols;
            this->m_rows = m.m_rows;
            
            return *this;
        }

        //! Method to find the cell on vector by coordinates( x, y).
        /*! 
        \param int x Coordinates X.
        \param int y Coordinates Y.
        \return int Place on vector.
        */
        int find_cell( int x, int y)
        {
            if( y == 0)
            {
                return x;
            }
            if(x == 0)
            {
                return y*m_cols;
            }

            return x + y*m_cols;
        }

        //! Method to change bit corresponding status cell to one.
        /*! 
        \param int x Coordinates X.
        \param int y Coordinates Y.
        \param status_cell sc status to be change.
        */
        void set_cell_up( int x, int y, status_cell sc );
        //! Method to change bit corresponding status cell to one.
        /*! 
        \param int cell of the vector.
        \param status_cell sc status to be change.
        */
        void set_cell_up( int cell, status_cell sc );
        
        //! Method to change bit corresponding status cell to zero.
        /*! 
        \param int x Coordinates X.
        \param int y Coordinates Y.
        \param status_cell sc status to be change.
        */
        void set_cell_down( int x, int y, status_cell sc);
        //! Method to change bit corresponding status cell to zero.
        /*! 
        \param int cell of the vector.
        \param status_cell sc status to be change.
        */
        void set_cell_down( int cell, status_cell sc);
        
        //! Method to see all status of cell.
        /*! 
        \param int x Coordinates X.
        \param int y Coordinates Y.
        \return return byte them corresponding the cell.
        */
        bit get_cell( int x, int y);
        
        //! Method to check if the status cell sc is up.
        /*! 
        \param int x Coordinates X.
        \param int y Coordinates Y.
        \param status_cell sc status to be check.
        \return True if is up otherwise False
        */
        bool is_cell_up(int x, int y, status_cell sc);
        //! Method to check if the status cell sc is up.
        /*! 
        \param int Cell of the vector.
        \param status_cell sc status to be check.
        \return True if is up otherwise False
        */
        bool is_cell_up(int cell, status_cell sc);

        //! Method to check if the cell have be see.
        /*! 
        \param int Cell of the vector.
        \return True if the cell is way our discarted otherwise False
        */
        bool is_way_up(int cell);

        //! Method to get numbers of colums.
        /*! 
        \return numbers of cols
        */
        int get_cols( void );
        //! Method to get numbers of rows.
        /*! 
        \return numbers of rows
        */
        int get_rows( void );
        //! Method to get numbers of cell.
        /*! 
        \return numbers of cell(rows*cols)
        */
        int get_numb_cell( void );

        int get_maze_done( void );
        void set_maze_done( int x );
};



#endif
