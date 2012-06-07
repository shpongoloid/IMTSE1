/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Niek
 */

#include <ma.h>

#include "SneeuwMan.hpp"

// constructor
SneeuwMan::SneeuwMan( int positionX, int positionY )
{
	this->positionX = positionX;
	this->positionY = positionY;
}

// destructor
SneeuwMan::~SneeuwMan()
{
	// TODO Auto-generated destructor stub
}

// de sneeuwman laten bewegen
void SneeuwMan::move( int direction )
{
	this->positionX += direction;
}

// de y-positie van de sneeuwman instellen
void SneeuwMan::setHeight( int sneeuwPositie )
{
	this->positionY = sneeuwPositie;
}

// het tekenen van de sneeuwman
void SneeuwMan::draw()
{
	maSetColor( 0x888888 );    //Grijs
	maFillRect( this->positionX, this->positionY - 30, 30, 30 );
	maFillRect( this->positionX + 5, this->positionY - 50, 20, 20 );
}
