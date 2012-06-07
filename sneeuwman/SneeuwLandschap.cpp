/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 5 mrt. 2012
 *      Author: Niek
 */

#include "SneeuwLandschap.hpp"
#include "SneeuwVlok.hpp"

#include <mastdlib.h>

// globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;

// constructor
SneeuwLandschap::SneeuwLandschap()
{
	// sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	// stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	// hoeveel de sneeuw omhoog gaat, op het begin 0, het verhoogd als er sneeuw valt
	this->sneeuwUpper = 0;

	// maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}


// wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	// als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		// pak de key code
		int key = maGetKeys();

		// kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		// kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}

	// voeg een sneeuwvlok toe
	for( int i = 0; i < 7; i++ )
	{
		SneeuwVlok* sneeuwVlok = new SneeuwVlok( (rand()%screenWidth), 0);
		this->sneeuwVlokArray.add( sneeuwVlok );
	}

	// laat alle sneeuwvlokken vallen
	for( int i = 0; i < this->sneeuwVlokArray.size(); i++ )
	{
		this->sneeuwVlokArray[i]->fall( screenHeight );
	}
}

// wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	// kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	// maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	// teken de sneeuwman
	this->sneeuwMan->draw();

	// teken alle sneeuwvlokken
	for( int i = 0; i < this->sneeuwVlokArray.size(); i++ )
	{
		this->sneeuwVlokArray[i]->draw();

		// de sneeuwvlokken echt verwijderen
		if( this->sneeuwVlokArray[i]->isDead() )
		{
			delete sneeuwVlokArray[i];
			sneeuwVlokArray.remove(i);

			// zodra er 200 vlokjes gevallen zijn gaat de sneeuwhoogte met een pixel omhoog
			this->sneeuwUpper ++;
			if( this->sneeuwUpper > 200 )
			{
				this->sneeuwHoogte++;
				this->sneeuwUpper = 0;

				sneeuwMan->setHeight( screenHeight - this->sneeuwHoogte );
			}
		}
	}
	maUpdateScreen();
}
