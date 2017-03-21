/*!
 *   TODO
 *   Module description goes here...
 */

#include "../include/dice.h"


FaceType roll( FaceType n_faces_, std::random_device::result_type seed_ )
{
    //use the default random engine and an uniform distribution
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    if ( seed_ == 0 )
        std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
    else
        std::mt19937 gen( seed_ ); // Client's seed.

    std::mt19937 gen( ( ( seed_ == 0 ) ? rd() : seed_ ) ); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<FaceType> dis(0, n_faces_-1);

    return dis( gen );
}
