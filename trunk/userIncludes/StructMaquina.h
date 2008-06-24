#ifndef STRUCTMAQUINA_H_
#define STRUCTMAQUINA_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../userIncludes/StructTransicoes.h"



typedef struct StructMaquina
{
	std::vector<char>
	alfabetoEntrada;

	std::vector<std::string>
	conjuntoEstados;

	std::multimap<std::string,StructTransicoes>
	funcoesTransicao;

	std::string
	estadoInicial;

	std::vector<std::string>
	estadosFinais;

	std::vector<char>
	alfabetoFita;

	char
	caractereBranco;

	char
	caractereInicioFita;
};

#endif /*STRUCTMAQUINA_H_*/
