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

	protected:

	private:
		std::ifstream
		arquivo;

		std::multimap<std::string,StructTransicoes>
		transicoes;

		bool
		carregaArquivo( std::string );

		void
		leArquivo( );

		void
		parseiaOctupla( std::string, StructMaquina* );

		void
		parseiaTransicoes( );
};

#endif /*PARSERMAQUINA_H_*/
