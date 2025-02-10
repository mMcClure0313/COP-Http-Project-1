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

using namespace std;

int main(int argc, char *argv[]){
    if(argc < 3){
        cout << "please run the application like so: './httpClient <serverIdentifier> <fileToRequest/messageToSend>" << endl;
    } else{
        cout << "./httpClient\t" << argv[1] << "\t" << argv[2] << endl;
    }




    return 0;
}