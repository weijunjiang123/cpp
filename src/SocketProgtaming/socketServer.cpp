#include <iostream>
#include <string>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

bool initSocket();
bool CreateSocket(SOCKET &serverSocket);
bool BindSocket(SOCKET &serverSocket, string ip, int port);
bool ListenSocket(SOCKET &serverSocket, int backlog);

void startServer()
{
    SOCKET serverSocket;
    SOCKET clientSocket;
    string data;
    initSocket();
    CreateSocket(serverSocket);
    BindSocket(serverSocket, "0.0.0.0", 8080);
    ListenSocket(serverSocket, 5);

    bool isClientConnected = false;
    bool isrecv = false;

    while (true)
    {
        if (!isClientConnected)
        {
            cout << "Waiting for client connection..." << endl;
            clientSocket = accept(serverSocket, NULL, NULL);
            if (clientSocket == INVALID_SOCKET)
            {
                cout << "accept failed!" << endl;
                break;
            }
            cout << "Client connected!" << endl;
            isClientConnected = true;
        }
        if (isClientConnected)
        {
            char recvBuf[1024] = {0};
            int ret = recv(clientSocket, recvBuf, 1024, 0);
            if (ret == SOCKET_ERROR)
            {
                cout << "recv failed!" << endl;
                break;
            }
            if (ret == 0)
            {
                cout << "Client disconnected!" << endl;
                break;
            }
            cout << "Received: " << recvBuf << endl;
            if (strcmp(recvBuf, "exit") == 0)
            {
                cout << "Client disconnected!" << endl;
                break;
            }
            cout << "Send: ";
            getline(cin, data);
            ret = send(clientSocket, data.c_str(), data.length(), 0);
            if (ret == SOCKET_ERROR)
            {
                cout << "send failed!" << endl;
                break;
            }
            if (strcmp(data.c_str(), "exit") == 0)
            {
                cout << "Client disconnected!" << endl;
                break;
            }
        }
    }
}

bool initSocket()
{
    WSADATA wsaData;
    WORD version = MAKEWORD(2, 2);
    int ret = WSAStartup(version, &wsaData);
    if (ret != 0)
    {
        cout << "WSAStartup failed!" << endl;
        return false;
    }
    return true;
}

bool CreateSocket(SOCKET &serverSocket)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET)
    {
        cout << "socket failed!" << endl;
        return false;
    }
    return true;
}

bool BindSocket(SOCKET &serverSocket, string ip, int port)
{
    sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    sockAddr.sin_port = htons(port);
    int ret = bind(serverSocket, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));
    if (ret != 0)
    {
        cout << "bind failed!" << endl;
        return false;
    }
    return true;
}

bool ListenSocket(SOCKET &serverSocket, int backlog)
{
    int ret = listen(serverSocket, backlog);
    if (ret != 0)
    {
        cout << "listen failed!" << endl;
        return false;
    }
    return true;
}

int main()
{
    startServer();
}