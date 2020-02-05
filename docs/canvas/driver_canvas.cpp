#include <iostream>
#include <cstring>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


typedef unsigned char byte;
struct Color{
    byte channels[3];
    Color( byte r=0, byte g=0, byte b=0 ) : channels{ r, g, b }{/* empty */}
};

const Color BLACK( 0,0,0);
const Color WHITE( 255, 255, 255 );
const Color RED( 255, 0, 0 );
const Color YELLOW( 255, 255, 0 );

int main(void)
{

    /*
     === Classe canvas ===
    Canvas(w,h);
    hline(x,y, w, cor);
    vline(x,y, h, cor);
    box(x,y, w, h, cor);
    clear( cor );
    byte * get_pixels();

    pixel( x,y, Cor )
    */


    size_t width = 400;
    size_t height = 300;
    byte * pixels = new byte[ width * height * 3 ];

    std::memset( pixels, 200, width * height * 3 );

    int x = 50;
    int y = 150;
    int len = 50; // Comprimento da linha.

    for( auto col(0) ; col < len ; col++ )
    {
        x++;
        size_t idx = y * width * 3 + x * 3;
        pixels[ idx + 0 ] = 255; // R
        pixels[ idx + 1 ] = 0; // G
        pixels[ idx + 2 ] = 0; // B
    }


    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( "teste.png",      // file name
                width, height,        // image dimensions
                3,                    // # of channels per pixel
                pixels,               // the pixels
                width*3)  ;           // length of a row (in bytes), see above.


