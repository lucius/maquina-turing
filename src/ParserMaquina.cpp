#include <iostream>
#include <iterator>
#include <map>

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

StructMaquina
ParserMaquina::getMaquina( )
{
	return this->maquina;
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

	this->parseiaOctupla( _buffer );

	while( this->arquivo.good() )
	{
		this->arquivo >> _buffer;
		this->parseiaTransicoes( _buffer );		
	}
}

void
ParserMaquina::parseiaOctupla( std::string _buffer)
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
	_caractereInicioFita;


	_alfabetoEntrada = this->removeChaves( &_buffer );
	_conjuntoEstados = this->removeChaves( &_buffer );
	_funcoesTransicao = this->removeChaves( &_buffer );
	_estadoInicial = this->removeChaves( &_buffer );
	_estadosFinais = this->removeChaves( &_buffer );
	_alfabetoFita = this->removeChaves( &_buffer );
	_caractereBranco = this->removeChaves( &_buffer );
	_caractereInicioFita = this->removeChaves( &_buffer );

	this->maquina.alfabetoEntrada = this->removeVirgulaChar( _alfabetoEntrada );
	this->maquina.conjuntoEstados = this->removeVirgulaStr( _conjuntoEstados );
	this->maquina.estadoInicial = _estadoInicial;
	this->maquina.estadosFinais = this->removeVirgulaStr( _estadosFinais );
	this->maquina.alfabetoFita = this->removeVirgulaChar( _alfabetoFita );
	this->maquina.caractereBranco = _caractereBranco.at( 0 );
	this->maquina.caractereInicioFita = _caractereInicioFita.at( 0 );
}

std::string
ParserMaquina::removeChaves( std::string* _buffer )
{
	size_t
	posicaoInicialCorte;

	size_t
	tamanhoCorte;

	std::string
	_retornoSemChaves;

	posicaoInicialCorte = _buffer->find_first_of('{')+1;
	tamanhoCorte = _buffer->find_first_of('}')-posicaoInicialCorte;
	_retornoSemChaves = _buffer->substr( posicaoInicialCorte, tamanhoCorte );

	*_buffer = _buffer->substr ( _buffer->find_first_of('}')+1 );

	return _retornoSemChaves;
}

void
ParserMaquina::parseiaTransicoes( std::string _buffer )
{
	StructTransicoes
	_auxiliarInsercao;

	size_t
	_limiteSuperiorCorte;

	_buffer = _buffer.substr( _buffer.find_first_of('(')+1 );

	_limiteSuperiorCorte = _buffer.find_first_of(',');
	_auxiliarInsercao.estadoOrigem = _buffer.substr( 0, _limiteSuperiorCorte );
	_buffer = _buffer.substr( _limiteSuperiorCorte+1 );

	_limiteSuperiorCorte = _buffer.find_first_of(')');
	_auxiliarInsercao.simboloLido = _buffer.substr( 0, _limiteSuperiorCorte ).at( 0 );
	_limiteSuperiorCorte = _buffer.find_first_of('[')+1;
	_buffer = _buffer.substr( _limiteSuperiorCorte );

	_limiteSuperiorCorte = _buffer.find_first_of(',');
	_auxiliarInsercao.estadoDestino = _buffer.substr( 0, _limiteSuperiorCorte );
	_buffer = _buffer.substr( _limiteSuperiorCorte+1 );

	_limiteSuperiorCorte = _buffer.find_first_of(',');
	_auxiliarInsercao.simboloEscrito = _buffer.substr( 0, _limiteSuperiorCorte ).at( 0 );
	_buffer = _buffer.substr( _limiteSuperiorCorte+1 );

	_limiteSuperiorCorte = _buffer.find_first_of(']');
	_auxiliarInsercao.direcaoCabecote = _buffer.substr( 0, _limiteSuperiorCorte ).at( 0 );

	this->maquina.funcoesTransicao.insert( std::pair<std::string,StructTransicoes>
										   (_auxiliarInsercao.estadoOrigem, _auxiliarInsercao) );
}

std::vector<char>
ParserMaquina::removeVirgulaChar( std::string _buffer )
{
	std::vector<char>
	_vectorRetorno;

	std::string
	_substring;
	
	while( !_buffer.empty() )
	{
		if( _buffer.find_first_of(',') != std::string::npos )
		{
			_substring = _buffer.substr( 0, _buffer.find_first_of(',') );
			_vectorRetorno.push_back( _substring.at(0) );
			_buffer = _buffer.substr( _buffer.find_first_of(',')+1 );
		}
		else
		{
			_substring = _buffer;
			_vectorRetorno.push_back( _substring.at(0) );
			_buffer.clear( );
		}
	}
	return _vectorRetorno;
}

std::vector<std::string>
ParserMaquina::removeVirgulaStr( std::string _buffer )
{
	std::vector<std::string>
	_vectorRetorno;

	std::string
	_substring;
	
	while( !_buffer.empty() )
	{
		if( _buffer.find_first_of(',') != std::string::npos )
		{
			_substring = _buffer.substr( 0, _buffer.find_first_of(',') );
			_vectorRetorno.push_back( _substring );
			_buffer = _buffer.substr( _buffer.find_first_of(',')+1 );
		}
		else
		{
			_substring = _buffer;
			_vectorRetorno.push_back( _substring );
			_buffer.clear( );
		}
	}
	return _vectorRetorno;
}
