# COP-Http-Project-1

## https://uwf.instructure.com/courses/58481/assignments/1101018


@authors: Matthew McClure, Hunter Seth Mercer

A simple server project where the server serves the client browser with an https page, with several links that will be handled as described by the project description

The application was tested by running make in a ubantu wsl terminal, and using a firefox browser as the client to connect to the server
using `make` will generate the httpServer executable, to be executed using `./httpServer` in the terminal

the server is opened on port 60060, if there as another application that specifically uses 60060, it will not work.

With the server running, opening up a webpage and entering localhost:60060 will open the web page.
The server will display the buffer contents to the terminal, and will show that it served the files needed to display the page.

Clicking on the link for the image and the nonexistant link will be handled appropriately.

There is an input for server text field that will allow for client input, and clicking send input will display the appropriate response in the terminal.

`make clean` will remove the httpServer from your directory.