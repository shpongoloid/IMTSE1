/*
 * SneeuwVlok.hpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Niek
 */

#include <ma.h>

#ifndef SNEEUWVLOK_HPP_
#define SNEEUWVLOK_HPP_

class SneeuwVlok
{
private:
	int positionX;	//sneeuwvlok heeft x positie
	int positionY;	//sneeuwvlok heeft y positie
	int size;		//sneeuwvlok heeft (een willekeurige) grootte
	int speed;		// snelheid van de fall
	int direction;	// snelheid van de fall

	bool dead;		//als dead == true, wordt de sneeuwvlok verwijdert

public:
	SneeuwVlok( int positionX, int positionY );	//constructor
	void draw();								//teken functie die een sneeuwvlok tekent
	void fall( int groundLevel );				//functie die de y positie verandert
	bool isDead();								//functie die de sneeuwvlok dead status teruggeeft
};
#endif /* SNEEUWVLOK_H_ */
