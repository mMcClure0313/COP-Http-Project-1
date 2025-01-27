# Compiler
CXX = g++

# Executable name
CXXFLAGS = -Wall -Wextra -g -std=c++11 -pthread

.PHONY: clean


TCPServer:
	$(CXX) $(CXXFLAGS) tcpServer.cpp -o TCPServer

tcpServer.o: tcpServer.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o TCPServer
