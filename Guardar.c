#include "TPO.h"

int GuardarUsuarios (NodeUser *primero, char *archivo)
{
  FILE* fd;
  NodeUser* aux;
  USU *datos;
  
  if((fd=fopen(archivo,"w"))==NULL)
    return 1;
  for(aux=primero;aux!=NULL;)
  {
    datos=&(aux->user);
    fwrite(datos,sizeof(USU),1,fd);
    primero=aux;
    aux=aux->nxt;
    free(primero);
  }
  fclose(fd);
  return 0;
}