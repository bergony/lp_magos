#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

#include "../include/render.h"
#include <string>

const Color GRAY( 200,200,200);
const Color BLACK( 0, 0, 0 );
const Color RED( 255, 0, 0);
const Color YELLOW (255,255,0);
const Color GREEN(0,0,255);
const Color BLUE(0,255,0);

void Render::draw( std::string s )
{
    m_canvas.clear( GRAY );     // Clear the canvas.

    const char *word = &s.at(0); // point begin of word

    int off_set_width = m_cell_width - ( m_cell_width * 95 ) / 100;      //Distance of lines
    int off_set_height = m_cell_height - ( m_cell_height * 95 ) / 100;   //Distance of lines

    for(int i{0}, y{0}; i < ( m_maze->get_rows() * m_cell_height ); y++, i += m_cell_height )
    {
        for(int j{0}, x{0}; j < ( m_maze->get_cols() * m_cell_width );x++, j += m_cell_width )
        {
            //Draw top line.
            if(y == 0 || ( m_maze->is_cell_up(y , x, Maze::status_cell::top) && m_maze->is_cell_up(y-1,x,Maze::status_cell::down) ) )
            {
                m_canvas.hline( 20+j , 20+i , m_cell_width, BLACK);
            }

            //Draw Left line.
            if(x == 0 || ( m_maze->is_cell_up(y, x, Maze::status_cell::left) && m_maze->is_cell_up(y,x-1,Maze::status_cell::right) ) )
            {
                m_canvas.vline(20+j , 20+i , m_cell_height, BLACK);
            }

            //Draw a yellow box if is way.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::way) )
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), YELLOW);         
            }

            //Draw a red box if is discarde.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::discarded) )
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), RED);         
            }

            //Draw the way to Top if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::way) &&  m_maze->is_cell_up(y-1 , x, Maze::status_cell::way) && !m_maze->is_cell_up( y, x,Maze::status_cell::top ) )
            {
                m_canvas.box(off_set_width+j, i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), YELLOW);         
            }
            //Draw the way to Left is true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::way) &&  m_maze->is_cell_up(y , x-1, Maze::status_cell::way) && !m_maze->is_cell_up( y, x,Maze::status_cell::left))
            {
                m_canvas.box(j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), YELLOW);
            }
            //Draw the way to Down if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::way) &&  m_maze->is_cell_up(y+1 , x, Maze::status_cell::way) && !m_maze->is_cell_up( y, x,Maze::status_cell::down))
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height, m_cell_width-(off_set_width*2), YELLOW);         
            }
            //Draw the way to right if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::way) &&  m_maze->is_cell_up(y , x+1, Maze::status_cell::way) && !m_maze->is_cell_up( y, x,Maze::status_cell::right))
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width, YELLOW);         
            }
            //Draw the Discarde to top if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::discarded) &&  m_maze->is_cell_up(y-1 , x, Maze::status_cell::discarded) && !m_maze->is_cell_up( y, x,Maze::status_cell::top))
            {
                m_canvas.box(off_set_width+j, i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), RED);         
            }
            //Draw the Discarde to left if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::discarded) &&  m_maze->is_cell_up(y , x-1, Maze::status_cell::discarded) && !m_maze->is_cell_up( y, x,Maze::status_cell::left))
            {
                m_canvas.box(j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width-(off_set_width*2), RED);         
            }
            //Draw the Discarde to down if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::discarded) &&  m_maze->is_cell_up(y+1 , x, Maze::status_cell::discarded) && !m_maze->is_cell_up( y, x,Maze::status_cell::down))
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height, m_cell_width-(off_set_width*2), RED);         
            }
            //Draw the Discarde to right if true.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::discarded) &&  m_maze->is_cell_up(y , x+1, Maze::status_cell::discarded) && !m_maze->is_cell_up( y, x,Maze::status_cell::right))
            {
                m_canvas.box(off_set_width+j, off_set_height+i, m_cell_height-(off_set_height*2), m_cell_width, RED);         
            }
            //Draw the exit box Green.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::exit) )
            {
                m_canvas.box((off_set_width*2)+j, (off_set_height*2)+i, m_cell_height-(off_set_height*4), m_cell_width-(off_set_width*4), GREEN);         
            }
            //Draw the Entrace Box Blue.
            if( m_maze->is_cell_up(y , x, Maze::status_cell::entrace) )
            {
                m_canvas.box((off_set_width*2)+j, (off_set_height*2)+i, m_cell_height-(off_set_height*4), m_cell_width-(off_set_width*4), BLUE);         
            }
        }
        //Draw Right Line.
        m_canvas.vline(20+(m_cell_width * m_maze->get_cols()), 20+i , m_cell_height , BLACK);
    }
    //Draw Down line.
    m_canvas.hline(20, 20+(m_cell_height*m_maze->get_rows() ), m_cell_width * m_maze->get_cols() + 1, BLACK);

    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( word,            // file name
            m_canvas.get_w(), m_canvas.get_h(),           // image dimensions
            3,                              // # of channels per pixel
            m_canvas.get_p(),                      // the pixels
            m_canvas.get_w()* 3);                 // length of a row (in bytes), see above.

}
