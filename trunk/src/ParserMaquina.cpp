#include <iostream>
#include <iterator>

#include "../userIncludes/LogErros.h"
#include "../userIncludes/ParserMaquina.h"
#include "../userIncludes/StructMaquina.h"
#include "../userIncludes/StructTransicoes.h"


ParserMaquina::ParserMaquina( std::string caminhoArquivo )
{
	if ( this->carregaArquivo(caminhoArquivo) )
	{
		this->leArquivo( );
	}
}

ParserMaquina::~ParserMaquina( )
{
	this->arquivo.close( );

	//LogErros::getInstancia().getLog();
}

bool
ParserMaquina::carregaArquivo( std::string caminhoArquivo )
{
	this->arquivo.open( caminhoArquivo.c_str(), std::ifstream::in );

	if ( this->arquivo.good() )
	{
		this->arquivo.seekg( 0, std::ios::beg );

		//std::cout << caminhoArquivo << std::endl << std::endl;

		return 1;
	}
	else
	{
		LogErros::getInstancia().insereErro( 0, "O caminho do arquivo está incorreto" );

		return 0;
	}
}

void
ParserMaquina::leArquivo( )
{
	std::string
	_buffer;

	StructMaquina
	maquinaTuring;
	
	this->arquivo >> _buffer;

	if( !_buffer.find_first_of('#') )
	{
		_buffer.clear( );
	}

	this->arquivo >> _buffer;

	this->parseiaOctupla( _buffer, &maquinaTuring );
}

void
ParserMaquina::parseiaOctupla( std::string _buffer, StructMaquina* maquinaTuring )
{
	std::string
	_alfabetoEntrada;

	std::string
	_conjuntoEstados;

	std::string
	_funcoesTransicao;

	std::string
	_estadoInicial;

	std::string
	_estadosFinais;

	std::string
	_alfabetoFita;

	std::string
	_caractereBranco;

	std::string
	_inicioFita;

	size_t
	posicaoInicialCorte;

	size_t
	tamanhoCorte;


	posicaoInicialCorte = _buffer.find_first_of('{')+1;
	tamanhoCorte = _buffer.find_first_of('}')-posicaoInicialCorte;
	_alfabetoEntrada = _buffer.substr( posicaoInicialCorte, tamanhoCorte );

	_buffer = _buffer.substr ( _buffer.find_first_of('}')+1 );

	posicaoInicialCorte = _buffer.find_first_of('{')+1;
	tamanhoCorte = _buffer.find_first_of('}')-posicaoInicialCorte;
	_conjuntoEstados = _buffer.substr( posicaoInicialCorte, tamanhoCorte );
	
	std::cout << _alfabetoEntrada;
	std::cout << _conjuntoEstados;

	//std::cout << _buffer;
}
