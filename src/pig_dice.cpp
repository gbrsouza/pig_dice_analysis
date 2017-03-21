#include <iostream>  // std::cout, std::cin, std::endl
#include <string>    // std::string

#include "../include/dice.h"

/// String representation for the dice's faces.
const std::string dice_faces[] = { "\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685" };

int main( void )
{

    // Roll the dice 10 times.
    for ( auto times(0u) ; times < 10 ; ++times )
        std::cout << ">>> Roll: " << dice_faces[ roll() ] << std::endl;

    return EXIT_SUCCESS;
}
