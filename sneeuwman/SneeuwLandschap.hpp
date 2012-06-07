/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Niek
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_

#include <ma.h>
#include <MAUtil/Vector.h>

#include "SneeuwMan.hpp"
#include "SneeuwVlok.hpp"

class SneeuwLandschap
{
private:
	int sneeuwHoogte;
	int sneeuwUpper;
	SneeuwMan* sneeuwMan;

	MAUtil::Vector<SneeuwVlok*> sneeuwVlokArray;

public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};


#endif /* SNEEUWLANDSCHAP_HPP_ */
