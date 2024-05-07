#pragma once

#include "LAGraph.h"

bool BreadthFirstTraversalLA(Graph* g, int vOrigin);
bool BreadthFirstSearchLA(Graph* g, int vOrigin, int valor);

//NOTA: colocar estes m�todos na lib
Vertice* ResetVertices(Vertice* inicio);
void ProcessaVertice(Vertice* v);