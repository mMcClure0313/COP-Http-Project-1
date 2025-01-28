/**
 * COP4635, SYSNET2
 * @authors Matthew McClure, Hunter Seth Mercer
 * @date 01/25/2025
 * 
 * Simple application used to start up a TCP server used to serve a TCP Client the index.html, testPressence.html and img.jpg included in the project folder.
 * Coded on a Windows 10 machine using Visual Studio code and ran through an Ubantu WSL terminal integreated in VSCode. 
 * 
 */


#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main(){
    
    char tcp_server_message[256] = " Hello, I am the TCP Server you successfully connected to!! \n\n               Bye Bye!!!\n\n";

    int TCP_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(TCP_server_socket == -1) {
        cerr << "Failed to create socket." << endl;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(39756); //Passing the port number.
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //Binds socket to ip address and port.
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    //Listens for a client
    listen(serverSocket, 5);

    int tcp_client_socket;
    tcp_client_socket = accept(tcp_server_socket, NULL, NULL);

    send(tcp_client_socket, tcp_server_message, sizeof(tcp_server_message), 0);

    close(tcp_server_socket)

    return 0;

 }

