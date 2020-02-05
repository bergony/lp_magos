#ifndef _BUILD_H_
#define _BUILD_H_

#include <set>
#include "maze.h"

/// <b>Class</b> Build <i>Class that recives a Maze to be Build.</i>
class Build
{
    private:

        Maze *m_maze;                               //!< Reference to a Maze
        std::vector< std::set<int> > m_sets_cell;   //!< Vector of Set of Cell.
        int m_set_done{0};                          //!< Count when number off cell have be add.

    public:

        //==================Special members========================
        /// ! Constructor Build
        /*!
        \param Maze *m Referece to a Maze. 
        */
        Build( Maze *m ): m_maze{m}
        {
            m_sets_cell.resize(m_maze->get_numb_cell());        //!<Change size of vector fill a All cell.

            for(int i{0}; i < m_maze->get_numb_cell(); i++)
            {
                std::set< int > my_set;     //!< Creates a set of Cell. 
                my_set.insert(i);           //!< Add a cell to to set.
                m_sets_cell[i] = my_set;    //!< Add Set to Vector.
            }
        }

        /// ! Constructor Build Default
        Build(){}
        /// ! Destructors Build.
        ~Build( void ) 
        {
            /*EMPTY*/
        }

        /// ! Copy Build.
        Build( const Build & clone )
        {
            m_maze = clone.m_maze;
            m_sets_cell = clone.m_sets_cell;
            m_set_done = clone.m_set_done;
        }

        /// ! Assignment operator.
        Build& operator=(const Build & b)
        {
            this->m_maze = b.m_maze;
            this->m_sets_cell = b.m_sets_cell;
            this->m_set_done = b.m_set_done;

            return *this;
        }
        
        //! Method to check if the Maze is done on Build.
        /*! 
        \return True a set is on the same set otherwise False. 
        */
        bool done( void );
        //! Method add Cell to lab.
        /*! 
        \return True if cell is add otherwise False. 
        */
        bool make( void );

        //! Method to check if two set is already in the same set.
        /*! 
        \param int s1 First set.
        \param int s2 Secontd Set.
        \return True if s1 is on s2 otherwise False. 
        */
        bool is_on_set( int s1, int s2 );
        //! Method Union to two set and them sub-set.
        /*! 
        \Param int s1 set to be union.
        \param int s2 set to be union. 
        */
        void union_sets( int s1 , int s2 );
};

#endif
