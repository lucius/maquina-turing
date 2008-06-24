#include <iostream>

#include "../userIncludes/MaquinaFita.h"

MaquinaFita::MaquinaFita( std::string _conteudoFita, char _caractereBranco )
{
	this->fita = _conteudoFita;
	this->cabecote = this->fita.begin( );
	this->caractereBranco = _caractereBranco;
}

MaquinaFita::~MaquinaFita( )
{
	
}

bool
MaquinaFita::moveCabecote( char _caractereLeitura, char _caractereEscrita, char _direcao )
{
	if ( _caractereLeitura == this->leCabecote() )
	{
		if ( (_direcao == 'L') || (_direcao == 'l') )
		{
			this->moveCabecoteEsquerda( );
			return true;
		}
		else if ( (_direcao == 'R') || (_direcao == 'r') )
		{
			this->moveCabecoteDireita( );
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

char
MaquinaFita::leCabecote( )
{
	return *(this->cabecote);
}

std::string
MaquinaFita::retornaFita( )
{
	return this->fita;
}

void
MaquinaFita::moveCabecoteDireita( )
{
	if ( this->cabecote == (this->fita.end()-1) )
	{
		this->fita.push_back( this->caractereBranco );
		this->cabecote = this->fita.end()-1;
	}
	else
	{
		++this->cabecote;
	}
}

void
MaquinaFita::moveCabecoteEsquerda( )
{
	if ( this->cabecote == this->fita.begin() )
	{
		this->fita = this->caractereBranco + this->fita;
		this->cabecote = this->fita.begin();
	}
	else
	{
		--this->cabecote;
	}
}
