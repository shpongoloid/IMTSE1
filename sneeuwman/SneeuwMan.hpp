/*
 * SneeuwMan.hpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Niek
 */

#include <ma.h>

#ifndef SNEEUWMAN_HPP_
#define SNEEUWMAN_HPP_

class SneeuwMan
{
private:
	int positionX;
	int positionY;

public:
	SneeuwMan( int positionX, int positionY );

	void move( int direction );
	void draw();
	void setHeight( int sneeuwPositie );

	virtual ~SneeuwMan();
};

#endif /* SNEEUWMAN_HPP_ */
