#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Create socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening == -1){
        cerr << "Can't create a socket!";
        return -1;
    }

    // Bind socket to a IP/Port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54001);
    inet_pton(AF_INET, "127.0.0.1", &hint.sin_addr);

    if(bind(listening, (struct sockaddr *) &hint, sizeof(hint)) == -1){
        cerr << "Can't bind to ip/port";
        return -2;
    }

    if(listen(listening, SOMAXCONN) == -1){
        cerr << "Can't listen";
        return -3;
    }
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clientSocket = accept(listening, (struct sockaddr *) &client, &clientSize);

    if (clientSocket == -1){
        cerr << "Problem with client connecting!";
        return -4;
    }

    return 0;
}
