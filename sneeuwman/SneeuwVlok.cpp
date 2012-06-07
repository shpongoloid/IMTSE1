/*
 * SneeuwVlok.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Niek
 */
#include <ma.h>
#include <mastdlib.h>

#include "SneeuwVlok.hpp"

// constructor
SneeuwVlok::SneeuwVlok( int positionX, int positionY )
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->size = rand()%6 + 1;
	this->direction = rand()%5 - 2;
	this->speed = rand()%7 + 3;
}

// sneeuwvlokjes tekenen
void SneeuwVlok::draw()
{
	maSetColor( 0xffffff );    //wit
	maFillRect( this->positionX, this->positionY, this->size, this->size );
}

// sneeuwvolkjes laten vallen, de snelheid is random en de sneeuwvlokjes kunnen in een bepaalde richting waaien
void SneeuwVlok::fall( int groundLevel )
{
	if(this->positionY < groundLevel)
	{
		this->positionY += speed;
		this->positionX += direction;
		this->dead = false;
	}
	else
		this->dead = true;
}

// sneeuwvlokje is niet meer :(
bool SneeuwVlok::isDead()
{
	return dead;
}

