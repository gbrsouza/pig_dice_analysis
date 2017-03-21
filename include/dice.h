#ifndef _PIG_DICE_H_
#define _PIG_DICE_H_

#include <string>   // std::string
#include <random>   // std::default_random_engine, std::uniform_real_distribution.

/// Enumaration for each dice face.
enum dice_t { FACE_1=0, FACE_2, FACE_3, FACE_4, FACE_5, FACE_6, N_FACES };

//  Dice face type.
using FaceType = unsigned short;

// Prototypes

/*!
 *  \brief Rolls n-faced dice.
 *  This function simulares a roll of n-faced dice.
 *  You might simulate a regular 6-sided dice  or a coin toss.
 *
 *
 *  \param n_faces_ Number of dice faces (a integer >0). Default is a 6-sided dice.
 *  \param seed_ Seed used to generate the random event. If nothing is informed, we assume (pseudo) random generation.
 *
 *  \note Providing the same `seed` means we got the same random numbers.
 *
 *  \return The value of one of the n faces, i.e. a value in {0, 1, 2, ..., n-1}.
 */
FaceType roll( FaceType =6, std::random_device::result_type =0 );

#endif
