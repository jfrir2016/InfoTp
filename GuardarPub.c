#include "TPO.h"

int GuardarPost (NodePost *primero, char *archivo)
{
  FILE* fd;
  NodePost* aux;
  POST *datos;
  
  if((fd=fopen(archivo,"w"))==NULL)
    return 1;
  for(aux=primero;aux!=NULL;)
  {
    datos=&(aux->publicacion);
    fwrite(datos,sizeof(POST),1,fd);
    primero=aux;
    aux=aux->nxt;
    free(primero);
  }
  fclose(fd);
  return 0;
}
