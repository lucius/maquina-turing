#ifndef MAQUINATURING_H_
#define MAQUINATURING_H_

#include <iostream>
#include <string>

#include "../userIncludes/MaquinaFita.h"
#include "../userIncludes/StructMaquina.h"



#define CHANGE_STRING 0
#define CHANGE_MACHINE 1

class MaquinaTuring
{
	public:
		MaquinaTuring( std::string );

		MaquinaTuring( std::string, std::string );

		~MaquinaTuring( );

		void
		setString( std::string );

		void
		carregaMaquina( std::string );

		bool
		executa( );

		bool
		executa( std::string, bool );

		bool
		executa( std::string, std::string );
	protected:

	private:
		MaquinaFita*
		fita;

		StructMaquina
		maquina;

		std::string
		stringInicial;

		std::string
		estadoAtual;
};

#endif /*MAQUINATURING_H_*/
