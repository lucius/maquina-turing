#include <iostream>

#include "../userIncludes/MaquinaTuring.h"
#include "../userIncludes/ParserMaquina.h"
#include "../userIncludes/StructMaquina.h"



MaquinaTuring::MaquinaTuring( std::string _string )
{
	this->setString( _string );
}

MaquinaTuring::MaquinaTuring( std::string _string, std::string _caminhoArquivo )
{
	this->carregaMaquina( _caminhoArquivo );
	this->setString( _string );
}

void
MaquinaTuring::setString( std::string _string )
{
	this->stringInicial = _string;
}


void
MaquinaTuring::carregaMaquina( std::string _caminhoArquivo )
{
	ParserMaquina*
	parser = new ParserMaquina ( _caminhoArquivo );

	this->maquina = parser->getMaquina( );
	this->estadoAtual = this->maquina.estadoInicial;
	
	delete parser;
}
