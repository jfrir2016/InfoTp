#include "TPO.h"

int BorrarPost (int fd, NodePost *PRoot)
{
  char* buffer[BUFFER];
  POST *find;
  int sel;
  
  buffer[BUFFER]=NULL; 						//pongo el ultimo puntero a NULL para saber que termino
   
  for(i=0; Aux!=NULL; i++)					//Creo vector de Titulos
  {
    buffer[i]=(char *)malloc(sizeof(strlen(Aux->post.titulo)+1));
    strcpy(buffer[i],Aux->post.titulo);
    Aux=Aux->nxt;
  }
  buffer[i]=NULL;
  
  if((send(fd,&i,sizeof(int),0,))==-1)				//Envio cantidad
    {
      perror("Send: ");
      exit(1);
    }
  for(i=0; buffer[i]!=NULL; i++)
  {
    if((send(fd,buffer[i],strlen(buffer[i])+1,0,))==-1)		//Envio titulo post a post
    {
      perror("Send: ");
      exit(1);
    }
  }
  
  if((recv(sockfd,&sel,sizeof(int),0,))==-1)			//Recivo seleccion
  {
    perror("Recv: ");
    exit(1);
  }
  find=BuscoPost(buffer[sel],PRoot);				//Busco publicacion a borrar
  if(!BorrarNodoPub(find->id,PRoot))				//Borro
  {
    printf("Error al agregar nodo\n");
    return 1;
  }
  return 0;
}

  