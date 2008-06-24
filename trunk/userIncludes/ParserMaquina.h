#ifndef PARSERMAQUINA_H_
#define PARSERMAQUINA_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "../userIncludes/StructMaquina.h"
#include "../userIncludes/StructTransicoes.h"



class ParserMaquina
{
	public:
		ParserMaquina( std::string );

		~ParserMaquina( );

		StructMaquina
		getMaquina( );

	protected:

	private:
		std::ifstream
		arquivo;

		StructMaquina
		maquina;

		bool
		carregaArquivo( std::string );

		void
		leArquivo( );

		void
		parseiaOctupla( std::string );

		void
		parseiaTransicoes( std::string );

		std::string
		removeChaves( std::string* );

		std::vector<char>
		removeVirgulaChar( std::string );

		std::vector<std::string>
		removeVirgulaStr( std::string );
};

#endif /*PARSERMAQUINA_H_*/
