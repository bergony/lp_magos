#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <cstring>
#include <stdio.h>

typedef unsigned char byte;

/// <b>Struct</b> Color <i> Color of to printer.</i>
struct Color
{
    byte chanels[3]; //!< Byte to save Colorss

    /// ! Constructor Color with black space.
    Color( byte red = 0, byte green = 0 , byte blue = 0 ) : chanels
    { red,          green,           blue }
    { /*EMPTY*/ }
};

/// <b>Class</b> Canvas <i>Class to creates a Canvas to be draw( Line and Box ).</i>
class Canvas
{
    private:

        int m_width; //!< Witdh of image.
        int m_height; //!< height of image.
        byte * m_pixels; //!< Pointer to begin of the Vector colors.

    public:

        //==================Special members========================
        /// ! Constructor Canvas
        /*!
          \param int w Witdh of Image.
          \param int h Height of Image .
          */
        Canvas( int w = 0, int h = 0 ) :
            m_width{w}, m_height{h},
            m_pixels{ new byte[ h * w *3 ] }
        {
            /* EMPTY */
        }

        /// ! Destructors Canvas
        ~Canvas( void )
        {
            delete m_pixels;
        }

        /// ! Copy Canvas.
        Canvas( const Canvas & clone )
        {
            m_width = clone.m_width;
            m_height = clone.m_height;
            byte * ptr{ new byte[m_width*m_height*3]};
            *ptr = *clone.m_pixels;
        }

        /// ! Assignment operator.
        Canvas& operator=( const Canvas & c)
        {
            this->m_width = c.m_width;
            this->m_height = c.m_height;
            byte *ptr{ new byte[m_width * m_height * 3]};
            *ptr = *c.m_pixels;

            return *this;
        }

        //! Method to get width of the Canvas.
        /*!
          \return int value of width
          */
        int get_w( void ) const;

        //! Method to get height of the Canvas.
        /*!
          \return int value of height
          */
        int get_h( void ) const;

        //! Method to get the Point of the begin Canvas.
        /*! \return A Point to a byte( Unsigned char )*/
        byte * get_p( void ) const;

        //! Printer the full Canvas with a Color param.
        /*!
          \param Color color chosen to fill the Canvas.
          */
        void clear( Color color );

        //! Printer a Horizontal line
        /*!
          \param const int & x coordinate X on Canvas.
          \param const int & y coordiante Y on Canvas.
          \param const int & w width( SIZE ) of line.
          \param Color color color chosen to fill the line
          */
        void hline( const int & x, const int & y, const int & w, Color color );

        //! Printer a Vertical line
        /*!
          \param const int & x coordinate X on Canvas.
          \param const int & y coordiante Y on Canvas.
          \param const int & h height( SIZE ) of line.
          \param Color color color chosen to fill the line
          */
        void vline( const int & x, const int & y, const int & h, Color color );

        //! Printer a Box
        /*!
          \param const int & x coordinate X on box.
          \param const int & y coordiante Y on box.
          \param const int & w width( SIZE ) of box.
          \param const int & h height( SIZE ) of box.
          \param Color color color chosen to fill the box
          */
        void box( const int & x, const int & y, const int & w, const int & h, Color color );

        //! Printer a single pixel on canvs
        /*!
          \param const int & x coordinate X on box.
          \param const int & y coordiante Y on box.
          \param Color color color chosen to fill the box
          */
        void pixel( const int & x, const int & y, Color color );

};

//end
#endif
