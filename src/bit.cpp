#include <iostream>
#include <bitset>

int main( void )
{

    unsigned char a = 5, b = 9, c = 0; // a = 5(00000101), b = 9(00001001)
    std::cout << "a = " << std::bitset<8>(a) << " b = " << std::bitset<8>(b) << "\n";
    c = a&b;
    std::cout << "a&b = " << std::bitset<8>(c) << "\n"; 
    c = a|b;
    std::cout << "a|b = " << std::bitset<8>(c) << "\n"; 
    c = a^b;
    std::cout << "a^b = " << std::bitset<8>(c) << "\n"; 

    std::cout << " Clear = 0 " << std::bitset<8>(0) << "\n"; 
    std::cout << " 1 = value " << std::bitset<8>(1) << "\n"; 
    std::cout << " 2 = value " << std::bitset<8>(2) << "\n"; 
    std::cout << " 4 = value " << std::bitset<8>(4) << "\n"; 
    std::cout << " 8 = value " << std::bitset<8>(8) << "\n"; 
    std::cout << "16 = value " << std::bitset<8>(16) << "\n"; 
    std::cout << "32 = value " << std::bitset<8>(32) << "\n"; 
    
    std::cout << " FUll = 63 "<< std::bitset<8>(63) << "\n"; 



    /*
     
    printf("a&b = %d\n", a&b); // The result is 00000001
    printf("a|b = %d\n", a|b);  // The result is 00001101
    printf("a^b = %d\n", a^b); // The result is 00001100
    printf("~a = %d\n", a = ~a);   // The result is 11111010
    printf("b<<1 = %d\n", b<<1);  // The result is 00010010
    printf("b>>1 = %d\n", b>>1);  // The result is 00000100i*/

    return 0;


    return 0;
}
