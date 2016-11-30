#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>

#define FUSU "Usuarios"
#define FPUB "Posts"

#define PORT 43210
#define BUFFER 255

typedef struct User
{
  int id;
  char Nombre[20];
  int Edad;
  char Usuario[20];
  char Contra[8];
  char email[35];
}USU;

typedef struct UserNode		//Usen esto para manejar usuarios en la lista
{
  struct User user;
  struct UserNode *nxt;
}NodeUser;

typedef struct Post
{
  int id;
  int idU;			//Id del usuario que la creo
  char titulo[20];
  char contenido[500];
  struct CommentNode *root;
}POST;

typedef struct PostNode		//Para manejar publicaciones en la lista
{
  struct Post post;
  struct PostNode *nxt;
}NodePost;

typedef struct Comentario
{
  int id;
  int idP;			//Id de la publicacion a la que pertenece
  int idU;			//Id del usuario que lo creo
  char contenido[241];
}COMMT;

typedef struct CommentNode
{
  struct Comentario comentario;
  struct CommentNode *nxt;
}NodeComment;


int GuardarUsuarios (USU *, char *);

int GuardarPost (NodePost *, char *);

int GuardarComents (NodePost *);

int LoadUsuarios (USU**, char *);

int LoadPubli (NodePost **,char *);

int LoadComments (NodePost **);

void sigchld_handler(int);

int AgregarNodoUsuario(USU*, NodeUser*);

void AgregarNodoComentario(COMMT*, NodePost*, NodeComment*);

void AgregarNodoPub(POST*, NodePost*);

int BorrarPub(int, NodePost);			//idem sig.

int BorrarUsuario(int, NodeUser);		//retorna 0 si se borro, 1 si no se encontro
 
int BorrarComentario(int, NodeComment);		//idem anterior

int Check (USU **,NodeUser *);