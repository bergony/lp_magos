#ifndef _RENDER_H_
#define _RENDER_H_

#include "../include/canvas.h"
#include "../include/maze.h"
#include <string>

/// <b>Class</b> Render <i>A class that recive Maze Object to draw in the Canvas.</i>
class Render
{
    private:

        Maze *m_maze;       //!< Maze to be draw.
        int m_cell_width;   //!< Width of the cell.
        int m_cell_height;  //!< Height of the cell.
        Canvas m_canvas;    //!< Canvas to draw.

    public:

        //==================Special members========================
        /// ! Constructor Render
        /*!
          \param int *M Reference to Maze. 
          \param int w width of Image.
          \param int h height of Image.
          */
        Render( Maze *m, int w = 0, int h = 0 ) : m_maze{m}, m_cell_width{w}, m_cell_height{h}, m_canvas{ w , h }
        {
            m_cell_width = (w-40) / m_maze->get_cols();
            m_cell_height = (h-40) / m_maze->get_rows();
        }

        /// ! Destructors Canvas
        ~Render() { /* EMPTY */ }

        /// ! Copy Canvas.
        Render( const Render & clone )
        {
            m_maze = clone.m_maze;
            m_cell_width = clone.m_cell_width;
            m_cell_height = clone.m_cell_width;
            m_canvas = clone.m_canvas;
        }

        /// ! Assignment operator.
        Render& operator=( const Render & r)
        {
            this->m_maze = r.m_maze;
            this->m_cell_width = r.m_cell_width;
            this->m_cell_height = r.m_cell_width;
            this->m_canvas = r.m_canvas;

            return *this;
        }

        //! Method to draw the Canvas.
        /*! 
          \param std::string s name of string output. 
          */
        void draw( std::string s );

};

#endif
