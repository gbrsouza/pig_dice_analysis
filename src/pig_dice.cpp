#include <iostream>  // std::cout, std::cin, std::endl
#include <string>    // std::string

#include "../include/dice.h"

/// String representation for the dice's faces.
const std::string dice_faces[] = { "\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685" };

int main( void )
{
	int player1 = 0;
	int player2 = 0;
	int hold = 0 ;

	bool answerHold = true;
	bool identifier = true; //true - jogador 1, false - jogador 2;

	while ((player1 < 20) && (player2 < 20)){
		if (identifier){
			std::cout << "\tVez do jogador 1" << std::endl;
		}else {
			std::cout << "\tVez do jogador 2" << std::endl;
		}
		std::cout << "\tDeseja jogar o dado?  -  1 sim, 0 não" << std::endl;
		std::cin >> answerHold;
		if (answerHold){
			auto dice = roll();
			std::cout << "\t>>> Sua Jogada: " << dice_faces[ dice ] << std::endl;

			if (dice == 0){
				std::cout << "\tQue peninha, você perdeu... :(" << std::endl;
				std::cout << "\tVez do próximo jogador!" << std::endl;
				if (identifier){
					identifier = false; // passa para jogador 2
					hold = 0;
				}else {
					identifier = true; // passa para jogador 1
					hold = 0;
				}
			}else {
				std::cout << "\tNooooossa :o, que sorte!" << std::endl;
				hold += dice+1;
				std::cout << "\tSeus pontos na rodada: " << hold << std::endl;
			}
		}else {
			if (identifier){
				player1 += hold;
				hold = 0;
				identifier = false;
				std::cout << std::endl;
				std::cout << "Jogador 1 Você possui " << player1 << " Pontos!!!!";
				std::cout << std::endl;
			}else{
				player2 += hold;
				hold = 0;
				identifier = true;
				std::cout << std::endl;
				std::cout << "Jogador 2 Você possui " << player2 << " Pontos!!!!";
				std::cout << std::endl;
			}
		}
	}

	if (player1 > player2){
		std::cout << "+-------------------------------------------+";
		std::cout << "|                  VENCEDOR!                |";
		std::cout << "|                                           |";
		std::cout << "|               >>>Jogador 1<<<             |";
		std::cout << "|                                           |";
		std::cout << "+-------------------------------------------+";
	}else{
		std::cout << "+-------------------------------------------+";
		std::cout << "|                  VENCEDOR!                |";
		std::cout << "|                                           |";
		std::cout << "|               >>>Jogador 2<<<             |";
		std::cout << "|                                           |";
		std::cout << "+-------------------------------------------+";
	}


    // Roll the dice 10 times.
    // for ( auto times(0u) ; times < 10 ; ++times )
    //     std::cout << ">>> Roll: " << dice_faces[ roll() ] << std::endl;



    return EXIT_SUCCESS;
}
