#include "TPO.h"

void AgregarNodoUsuario(USU *usuario, NodeUser *root)
{
  NodeUser *current=root;
  while(current->nxt!=NULL){
    current=current->nxt;
  }current->user=*usuario;
  return;
}