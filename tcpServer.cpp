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

    int TCP_Server_Socket = socket(AF_INET, SOCK_STREAM, 0);
    if(TCP_Server_Socket == -1) {
        cerr << "Failed to create socket." << endl;
    }

 }

