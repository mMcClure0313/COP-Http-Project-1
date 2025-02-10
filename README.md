# COP-Http-Project-2

## https://uwf.instructure.com/courses/58481/assignments/1101019


@authors: Matthew McClure, Hunter Seth Mercer

A client project with the previously made HTTP Server from the first project where a client is able to make calls and requests to the server to serve up files on request.

The application was tested by running make in a ubantu wsl terminal
using `make` will generate the httpServer and httpClient executable, to be executed using `./httpServer` and `./httpClient` in the terminal respectively.

the server is opened on port 60060, if there as another application that specifically uses 60060, it will not work.

With the server running, the httpClient needs the argument of the server to connect to in order to begin functionality.



`make clean` will remove the httpServer and httpClient from your directory.