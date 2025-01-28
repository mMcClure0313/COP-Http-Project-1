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
    
    int tcp_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(tcp_server_socket == -1) {
        cerr << "Failed to create socket." << endl;
    }
    cout << "Server socket created" << endl << endl;

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(39756); //Passing the port number.
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //Binds socket to ip address and port.
    bind(tcp_server_socket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    cout << "server created" << endl << endl;
    //Listens for a client
    cout << "server listening for a connection" << endl << endl;
    listen(tcp_server_socket, 5);

    while(true){
        int tcp_client_socket;
        tcp_client_socket = accept(tcp_server_socket, NULL, NULL);

        if(tcp_client_socket < 0){
            cerr << "Accept failed";
            continue;
        }

        const char* htmlResponse =
            "HTTP/1.1 200 OK\r\n"           //Header
            "Content-Type: text/html\r\n"   //Header
            "\r\n"
            "<!DOCTYPE html>\n"
            "<html>\n"
            "<head><title>Simple Server</title></head>\n"
            "<body>\n"
            "<h1>Hello from the TCP Server!</h1>\n"
            "<p>This is a simple HTML page served by the server.</p>\n"
            "</body>\n"
            "</html>\n";

        send(tcp_client_socket, htmlResponse, strlen(htmlResponse), 0);

        close(tcp_client_socket);
    }

    return 0;

 }

