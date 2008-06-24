#include <iostream>

#include "../userIncludes/ParserMaquina.h"
#include "../userIncludes/LogErros.h"

int main ( int argc, char** argv )
{
	ParserMaquina*
	teste;

	if ( argc > 1 )
	{
		teste = new ParserMaquina( argv[1] );

		delete teste;
	}

	return ( EXIT_SUCCESS );
}
