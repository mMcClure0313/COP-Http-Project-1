/**
 * COP4635, SYSNET2
 * @authors Matthew McClure, Hunter Seth Mercer
 * @date 02/08/2025
 * 
 * An application used to connect to the httpServer from project 1, and request files and send messages as needed.
 * Coded on a Windows 10 machine using Visual Studio code and ran through an Ubantu WSL terminal integreated in VSCode. 
 * 
 * To close the client, you press ctrl+c in the terminal.
 */


#include <iostream>
#include <stdio.h> //Standard library
#include <stdlib.h> //Standard library

#include <string.h> // For strlen, strcpy, strtok

#include <sys/socket.h> //API and definitions for the sockets
#include <sys/types.h> //more definitions
#include <netinet/in.h> //Structures to store address information
#include <arpa/inet.h> // For inet_pton
#include <sys/types.h>  // socket data types
#include <sys/socket.h> // socket functions
#include <unistd.h>

using namespace std;

void handleServer(){

}

int findSymbol(const char arr[], char target){

    if (arr == nullptr) return -1; 

    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
    //Specify program usage and debug statements.
    if(argc != 3){
        cout << "please run the application like so: './httpClient <serverIdentifier:portNumber> <fileToRequest/messageToSend>" << endl;
        return -1;
    } else{
        cout << argv[0] << "\t" << argv[1] << "\t" << argv[2] << endl;
    }

        //Separate address from the port
        int separator = findSymbol(argv[1], ':');
        if(separator == -1){
            cout << "Please indicate the server as <serverAddress>:<port#>" << endl;
            return -1;
        }

            // Extract IP and Port
            char serverIP[separator + 1];
            strncpy(serverIP, argv[1], separator);
            serverIP[separator] = '\0';
            int port = atoi(argv[1] + separator + 1);

            cout << "Connecting to " << serverIP << " on port " << port << endl;


        int tcp_client_socket; //Socket descriptor
        tcp_client_socket = socket(AF_INET, SOCK_STREAM, 0); //Calling the socket function - args: socket domain, socket stream type, TCP protocol (default)
        struct sockaddr_in tcp_server_address;
        tcp_server_address.sin_family = AF_INET; //Structure Fields' definition: Sets the address family of the address the client would connect to

        tcp_server_address.sin_port = htons(60060); //Specify and pass the port number to connect - converting in right network byte order

        if(inet_pton(AF_INET, serverIP, &tcp_server_address.sin_addr) <= 0){ //connects to the ip address specified. <= 0 means unsupported.
            cerr << ("Invalid or unsupported address") << endl;
            return -1;
        }

        //connecting to the remote socket
        int connection_status = connect(tcp_client_socket, (struct sockaddr *) &tcp_server_address, sizeof(tcp_server_address)); //params: which socket, castfor address to the specific structure type, size of address
       
        if (connection_status == -1){
        //return value of 0 means all okay, -1 means a problem
        printf(" Problem connecting to the socket! Sorry!! \n");
        }

        //Send the loaded message.
        send(tcp_client_socket, argv[2], strlen(argv[2]), 0);

        /**
         * Here's where I think a lot needs to change. The client application needs to remain after every send. We could do a while loop, exit on an argument 'exit' entering.
         * offset the sending of a message, socket conection build up and teardown to another function, as done in the server. I don't know if the server would even be able to support
         * a persistent connection.
         */


        char tcp_server_response[256];
        recv(tcp_client_socket, &tcp_server_response, sizeof(tcp_server_response), 0);
        // params: where (socket), what (string), how much - size of the server response, flags (0)
        //Output, as received from Server
        cout << "\n\n Server says: \n" << tcp_server_response << "\n\n";
        //closing the socket
        close(tcp_client_socket);



    return 0;
}