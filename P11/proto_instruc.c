#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> //struct sockaddr_in
#include <netinet/in.h> //PF_INET ->IPv4
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1357  // puerto de conexion

int main(void) {
  int sockfd, new_sockfd;  // descriptores de archivo
  struct sockaddr_in host_addr, client_addr;  // Informacion de las direcciones IP
  socklen_t sin_size;
  int recv_length=1, yes=1;
  char buffer[1024];

  if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    perror("Error al crear el socket");

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    perror("Error al agregar la opcion SO_REUSEADDR en setsockopt");
  
  host_addr.sin_family = AF_INET;     // 
  host_addr.sin_port = htons(PORT);   // htons -> bigendian
  host_addr.sin_addr.s_addr = INADDR_ANY; // Asigno mi IPP
  memset(&(host_addr.sin_zero), '\0', 8); // El resto de la estructura en 0s

  if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
    perror("Error haciendo el bind");

  if (listen(sockfd, 5) == -1) // 
    perror("Error al escuchar en el socket");

  while(1) {    // Accept loop
    sin_size = sizeof(struct sockaddr_in);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
    if(new_sockfd == -1)
      perror("Error al aceptar la conexion");
    printf("server: Conexion aceptada desde %s desde  %d\n",inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    send(new_sockfd, ":v\n", 3, 0);
    memset(buffer,0,sizeof(buffer)); // Para borrar buffer y que no se quede con basura
    recv_length = recv(new_sockfd, &buffer, 1024, 0);
    while(recv_length > 0) {
      // Si se escribe salir, se termina la conexión 
      if (strcmp(buffer,"salir\n") == 0) {
        break; // Terminamos la conexión 
      }
      // Se compara con instructor para entrar al protocolo
      if (strcmp(buffer,"instructor\n") == 0) {
        printf("Entró al protocolo instructor\n");
        // Ciclo para mantenerse en el protocolo hasta que se escriba "adios"
        while(strcmp(buffer,"adios\n") != 0){
          memset(buffer,0,sizeof(buffer)); // Para borrar buffer y que no se quede con basura
          recv_length = recv(new_sockfd, &buffer, 1024, 0);
          printf("Recibiendo: %s\n",buffer);
          if (strcmp(buffer,"ninos\n") == 0) 
            // printf("Soy Quintero\n\n");
            send(new_sockfd, "Soy Quintero\n", 13, 0);
          else if (strcmp(buffer,"no se\n") == 0)
            // printf("Soy Angie\n\n");
            send(new_sockfd, "Soy Angie\n", 10, 0);
          else if (strcmp(buffer,"hoda\n") == 0)
            // printf("Soy Vedo\n\n");
            send(new_sockfd, "Soy Vedo\n", 9, 0);
          else if (strcmp(buffer,"eso no me toco\n") == 0)
            // printf("Soy Yeudiel\n\n");
            send(new_sockfd, "Soy Yeudiel\n", 12, 0);
          else
            // printf("Escribe una frase celebre de alguien del CERT | adios para salir\n\n");
            send(new_sockfd, "Escribe una frase celebre de alguien del CERT | adios para salir\n", 65, 0);
        }
        printf("Ya termino el protocolo\n\n");
      }
      else
      {
        printf("RECV: %d bytes\n", recv_length);
        printf("Recibiendo: %s\n",buffer);
      }
      memset(buffer,0,sizeof(buffer)); // Para borrar buffer y que no se quede con basura
      recv_length = recv(new_sockfd, &buffer, 1024, 0);
    }
    printf("Terminó socket\n\n");
    close(new_sockfd);
    // break; // Por si se quiere terminar la ejecución al terminar el socket (opcional)
  }
  return 0;
}