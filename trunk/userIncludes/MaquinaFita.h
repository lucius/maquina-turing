#ifndef MAQUINAFITA_H_
#define MAQUINAFITA_H_

#include <iostream>
#include <string>



class MaquinaFita
{
	public:
		MaquinaFita( std::string, char );

		~MaquinaFita( );

		bool
		moveCabecote( char, char, char );

		char
		leCabecote( );

		std::string
		retornaFita( );

	protected:
		std::string
		fita;

		std::string::iterator
		cabecote;

		char
		caractereBranco;

		char
		caractereInicioFita;

		void
		moveCabecoteDireita( );

		void
		moveCabecoteEsquerda( );

	private:

};

#endif /*MAQUINAFITA_H_*/
