#include <cstring>

#include  "../include/canvas.h"

int Canvas::get_w( void ) const { return m_width; }

int Canvas::get_h( void ) const { return m_height; }

byte * Canvas::get_p( void ) const { return m_pixels; }

void Canvas::clear( Color color )       
{
    for( int i{0}; i <= ( m_width * m_height * 3 ); i+=3 )
    {
        m_pixels[i] = color.chanels[0];
        m_pixels[i+1] = color.chanels[1];
        m_pixels[i+2] = color.chanels[2];
    }
}

void Canvas::hline( const int & x, const int & y, const int & w, Color color )
{
    for( int i{0}; i < w; i++ )
    {
        pixel( x+i , y,color );
    }
}

void Canvas::vline( const int & x, const int & y, const int & h, Color color )
{
    for( int i{0}; i < h; i++ )
    {
        pixel( x, y+i , color );
    }
}

void Canvas::box( const int & x, const int & y, const int & w, const int & h, Color color )
{
    for(int i{0}; i < w ; i++ )
    {
        hline( 20 + x , 20+y+i, h, color );
    }
}
void Canvas::pixel( const int & x, const int & y, Color color )
{
    m_pixels[ ( y*m_width*3 ) + x*3 ] = color.chanels[0];
    m_pixels[ ( y*m_width*3 ) + x*3 +1] = color.chanels[1];
    m_pixels[ ( y*m_width*3 ) + x*3 +2] = color.chanels[2];   
}
